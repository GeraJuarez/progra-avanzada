#!/usr/bin/expect -f
# For colors
proc capability cap {expr {![catch {exec tput -S << $cap}]}}
proc colorterm {} {expr {[capability setaf] && [capability setab]}}
proc tput args {exec tput -S << $args >/dev/tty}
array set color {black 0 red 1 green 2 yellow 3 blue 4 magenta 5 cyan 6 white 7}
proc foreground x {exec tput -S << "setaf $::color($x)" > /dev/tty}
proc background x {exec tput -S << "setab $::color($x)" > /dev/tty}
proc reset {} {exec tput sgr0 > /dev/tty}

#Test the program
eval spawn [lrange $argv 0 end]

#Put your test case here

send "NOT((A OR NOT B) AND (A OR B)) OR NOT (A AND NOT B OR TRUE)\r"
send "1 5 2\r"
send "1 0\r"
send "1 1\r"
send "1 -1\r"
send -- "-1 -1\r"
send -- "-1 1\r"
send "0 1 A\r"
send -- "-1 0 D\r"

expect "0 0" {foreground green; puts "PASSED";reset} default {foreground red;puts "FAILED";reset}
expect "1 0" {foreground green; puts "PASSED";reset} default {foreground red;puts "FAILED";reset}
expect "1 -1" {foreground green; puts "PASSED";reset} default {foreground red;puts "FAILED";reset}
expect "0 -1" {foreground green; puts "PASSED";reset} default {foreground red;puts "FAILED";reset}
expect -- "-1 -1" {foreground green; puts "PASSED";reset} default {foreground red;puts "FAILED";reset}
expect -- "-1 0" {foreground green; puts "PASSED";reset} default {foreground red;puts "FAILED";reset}
expect -- "-1 1" {foreground green; puts "PASSED";reset} default {foreground red;puts "FAILED";reset}
expect "0 1" {foreground green; puts "PASSED";reset} default {foreground red;puts "FAILED";reset}
expect "1 1" {foreground green; puts "PASSED";reset} default {foreground red;puts "FAILED";reset}
