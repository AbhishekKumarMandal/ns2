set ns [new Simulator]

set traceFile [open 1.tr w]
$ns trace-all $traceFile

set namFile [open 1.nam w]
$ns namtrace-all $namFile

proc finish {} {
 global ns namFile traceFile
 $ns flush-trace
 close $namFile
 close $traceFile
 exec awk -f stats.awk 1.tr &
 exec nam 1.nam &
 exit 0
}

set n(0) [$ns node]
set n(1) [$ns node]
set n(2) [$ns node]

$n(0) color red
$n(2) color blue

$ns duplex-link $n(0) $n(1) 0.5Mb 20ms DropTail
$ns duplex-link $n(1) $n(2) 0.5Mb 20ms DropTail
$ns queue-limit $n(0) $n(1) 10
$ns queue-limit $n(1) $n(2) 10

set udp [new Agent/UDP]
$ns attach-agent $n(0) $udp

set null [new Agent/Null]
$ns attach-agent $n(2) $null

$ns connect $udp $null

set cbr [new Application/Traffic/CBR]
$cbr set packetSize_ 512
$cbr set interval_ 0.005
$cbr attach-agent $udp

$ns at 0.5 "$cbr start"
$ns at 2.0 "$cbr stop"
$ns at 2.0 "finish"
$ns run
