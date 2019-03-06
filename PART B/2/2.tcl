set ns [new Simulator]

set traceFile [open 2.tr w]
$ns trace-all $traceFile

set namFile [open 2.nam w]
$ns namtrace-all $namFile

proc finish {} {
 global ns namFile traceFile
 $ns flush-trace
 close $namFile
 close $traceFile
 exec awk -f stats.awk 2.tr &
 #exec nam 2.nam &
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

set tcp0 [new Agent/TCP]
$tcp0 set rate_ 100Kb
$tcp0 set packetSize_ 256
$ns attach-agent $n(0) $tcp0

set sink0 [new Agent/TCPSink]
$ns attach-agent $n(3) $sink0

$ns connect $tcp0 $sink0

set telnet [new Application/Telnet]
$telnet attach-agent $tcp0

set tcp1 [new Agent/TCP]
$tcp1 set rate_ 100Kb
$tcp1 set packetSize_ 512
$ns attach-agent $n(1) $tcp1

set sink1 [new Agent/TCPSink]
$ns attach-agent $n(3) $sink1

$ns connect $tcp1 $sink1

set ftp [new Application/FTP]
$ftp attach-agent $tcp1

$n(0) color blue
$n(1) color green
$n(3) color red

$ns at 0.5 "$telnet start"
$ns at 0.6 "$ftp start"
$ns at 10.0 "$telnet stop"
$ns at 10.0 "$ftp stop"
$ns at 10.5 "finish"

$ns run
