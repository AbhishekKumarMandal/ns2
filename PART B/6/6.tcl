set ns [new Simulator]

set error_rate 0.01

set traceFile [open 6.tr w]
$ns trace-all $traceFile

set namFile [open 6.nam w]
$ns namtrace-all $namFile

proc finish {} {
 global ns namFile traceFile
 $ns flush-trace
 close $traceFile
 close $namFile
 exec awk -f stats.awk 6.tr &
 exec nam 6.nam &
 exit 0
}

for {set i 0} {$i < 6} {incr i} {
 set n($i) [$ns node]
}

$ns duplex-link $n(0) $n(2) 2Mb 10ms DropTail
$ns duplex-link $n(1) $n(2) 2Mb 10ms DropTail
$ns duplex-link $n(2) $n(3) 0.3Mb 100ms DropTail

$ns queue-limit $n(2) $n(3) 20

set lan [$ns newLan "$n(3) $n(4) $n(5)" 0.5Mb 40ms LL Queue/DropTail MAC/802_3 Channel]

$ns duplex-link-op $n(0) $n(2) orient right-up
$ns duplex-link-op $n(1) $n(2) orient right-down
$ns duplex-link-op $n(2) $n(3) orient right

set loss_module [new ErrorModel]
$loss_module ranvar [new RandomVariable/Uniform]
$loss_module drop-target [new Agent/Null]
$loss_module set rate $error_rate
$ns lossmodel $loss_module $n(2) $n(3)

$ns color 1 Red
$ns color 2 Blue
$n(0) label "tcp source"
$n(1) label "udp source"

set tcp [new Agent/TCP]
$tcp set packetSize_ 256
$tcp set fid_ 1
$ns attach-agent $n(0) $tcp
set sink [new Agent/TCPSink]
$ns attach-agent $n(4) $sink
$ns connect $tcp $sink

set ftp [new Application/FTP]
$ftp attach-agent $tcp

set udp [new Agent/UDP]
$ns attach-agent $n(1) $udp
set null [new Agent/Null]
$ns attach-agent $n(5) $null
$ns connect $udp $null

set cbr [new Application/Traffic/CBR]
$cbr set packetSize_ 512
$cbr set fid_ 2
$cbr attach-agent $udp

$ns at 0.5 "$ftp start"
$ns at 0.6 "$cbr start"
$ns at 10.0 "$ftp stop"
$ns at 10.0 "$cbr stop"
$ns at 10.5 "finish"

$ns run
