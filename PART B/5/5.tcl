set ns [new Simulator]

set traceFile [open 5.tr w]
$ns trace-all $traceFile

set namFile [open 5.nam w]
$ns namtrace-all $namFile

proc finish {} {
 global ns namFile traceFile
 $ns flush-trace
 close $traceFile
 close $namFile
 exec awk -f stats.awk 5.tr &
 exec nam 5.nam &
 exit 0
}

for {set i 0} {$i < 7} {incr i} {
 set n($i) [$ns node]
}

$ns duplex-link $n(0) $n(2) 2Mb 10ms DropTail
$ns duplex-link $n(1) $n(2) 2Mb 10ms DropTail
$ns duplex-link $n(2) $n(3) 900Kb 10ms DropTail

set lan [$ns newLan "$n(3) $n(4) $n(5) $n(6)" 0.5Mb 40ms LL Queue/DropTail MAC/Csma/Cd Channel]

$ns duplex-link-op $n(0) $n(2) orient right-down
$ns duplex-link-op $n(1) $n(2) orient right-up
$ns duplex-link-op $n(2) $n(3) orient right

$ns queue-limit $n(0) $n(2) 10
$ns queue-limit $n(1) $n(2) 10
$ns queue-limit $n(2) $n(3) 9

$ns color 1 red
$ns color 2 blue

$n(0) color red
$n(1) color blue
$n(0) label "tcp source"
$n(1) label "udp source"

set tcp [new Agent/TCP]
$ns attach-agent $n(0) $tcp
$tcp set fid_ 1
$tcp set packetSize_ 256

set sink [new Agent/TCPSink]
$ns attach-agent $n(4) $sink
$ns connect $tcp $sink

set ftp [new Application/FTP]
$ftp attach-agent $tcp

set udp [new Agent/UDP]
$ns attach-agent $n(1) $udp
set null [new Agent/Null]
$ns attach-agent $n(6) $null
$ns connect $udp $null

set cbr [new Application/Traffic/CBR]
$cbr set packetSize_ 450
$cbr set fid_ 2
$cbr attach-agent $udp

$ns at 0.5 "$ftp start"
$ns at 0.6 "$cbr start"
$ns at 10.0 "$ftp stop"
$ns at 10.0 "$cbr stop"
$ns at 10.5 "finish"

$ns run
