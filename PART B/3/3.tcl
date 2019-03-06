set ns [new Simulator]

set traceFile [open 3.tr w]
$ns trace-all $traceFile

set namFile [open 3.nam w]
$ns namtrace-all $namFile

proc finish {} {
 global ns namFile traceFile
 $ns flush-trace
 close $namFile
 close $traceFile
 exec awk -f stats.awk 3.tr &
 #exec nam 3.nam &
 exit 0
}

for {set i 0} {$i < 4} {incr i} {
 set n($i) [$ns node]
}

$ns duplex-link $n(0) $n(2) 2Mb 10ms DropTail
$ns duplex-link $n(1) $n(2) 2Mb 10ms DropTail
$ns duplex-link $n(2) $n(3) 900Kb 10ms DropTail

$ns queue-limit $n(0) $n(2) 10
#$ns queue-limit $n(1) $n(2) 9
#$ns queue-limit $n(2) $n(3) 8

$n(0) color blue
$n(1) color green
$n(0) label "tcp source"
$n(1) label "udp source"
$n(3) color red

set tcp [new Agent/TCP]
$ns attach-agent $n(0) $tcp
set sink [new Agent/TCPSink]
$ns attach-agent $n(3) $sink

$ns connect $tcp $sink

set ftp [new Application/FTP]
$ftp attach-agent $tcp

set udp [new Agent/UDP]
$ns attach-agent $n(1) $udp
set null [new Agent/Null]
$ns attach-agent $n(3) $null

$ns connect $udp $null

set cbr [new Application/Traffic/CBR]
$cbr set packetSize_ 512
$cbr set interval_ 0.005
$cbr attach-agent $udp

$ns at 0.5 "$ftp start"
$ns at 0.6 "$cbr start"
$ns at 10.0 "$ftp stop"
$ns at 10.0 "$cbr stop"
$ns at 10.5 "finish"

$ns run
