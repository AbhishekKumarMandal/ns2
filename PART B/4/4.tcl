set ns [new Simulator]

set traceFile [open 4.tr w]
$ns trace-all $traceFile

set namFile [open 4.nam w]
$ns namtrace-all $namFile

proc finish {} {
 global ns namFile traceFile
 $ns flush-trace
 close $namFile
 close $traceFile
 exec awk -f stats.awk 4.tr &
 exec nam 4.nam &
 exit 0
}

for {set i 0} {$i < 7} {incr i} {
 set n($i) [$ns node]
}

for {set i 1} {$i < 4} {incr i} {
 $ns duplex-link $n(0) $n($i) 1Mb 10ms DropTail
}

$ns duplex-link $n(0) $n(4) 2Mb 20ms DropTail
$ns duplex-link $n(0) $n(5) 2Mb 20ms DropTail
$ns duplex-link $n(0) $n(6) 1Mb 10ms DropTail

for {set i 1} {$i < 6} {incr i} {
 $ns queue-limit $n(0) $n($i) 2
 }
$ns queue-limit $n(0) $n(6) 1
 
Agent/Ping instproc recv {from rtt} {
 $self instvar node_
 puts "node [$node_ id] received ping from $from with round trip time $rtt ms."
}

for {set i 1} {$i < 7} {incr i} {
 set pingagent($i) [new Agent/Ping]
 $ns attach-agent $n($i) $pingagent($i)
}

$ns connect $pingagent(1) $pingagent(4)
$ns connect $pingagent(2) $pingagent(5)
$ns connect $pingagent(3) $pingagent(6)

$ns at 0.1 "$pingagent(1) send"
$ns at 0.3 "$pingagent(2) send"
$ns at 0.5 "$pingagent(3) send"
$ns at 0.7 "$pingagent(4) send"
$ns at 0.9 "$pingagent(5) send"
$ns at 1.1 "$pingagent(6) send"
$ns at 1.3 "$pingagent(1) send"
$ns at 1.5 "$pingagent(2) send"
$ns at 1.7 "$pingagent(3) send"
$ns at 1.9 "$pingagent(4) send"
$ns at 2.1 "$pingagent(5) send"
$ns at 2.3 "$pingagent(6) send"
$ns at 2.5 "$pingagent(1) send"
$ns at 3.0 "finish"
$ns run
