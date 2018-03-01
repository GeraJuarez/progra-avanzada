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
send "0\r"
expect "true" {foreground green; puts "PASSED";reset} default {foreground red;puts "FAILED";reset}

#Test the program
eval spawn [lrange $argv 0 end]
send "0.1\r"
expect "true" {foreground green; puts "PASSED";reset} default {foreground red;puts "FAILED";reset}

#Test the program
eval spawn [lrange $argv 0 end]
send "abc\r"
expect "false" {foreground green; puts "PASSED";reset} default {foreground red;puts "FAILED";reset}

#Test the program
eval spawn [lrange $argv 0 end]
send "1a\r"
expect "false" {foreground green; puts "PASSED";reset} default {foreground red;puts "FAILED";reset}

#Test the program
eval spawn [lrange $argv 0 end]
send "2e10\r"
expect "true" {foreground green; puts "PASSED";reset} default {foreground red;puts "FAILED";reset}

#Test the program
eval spawn [lrange $argv 0 end]
send " 1,0000\r"
expect "false" {foreground green; puts "PASSED";reset} default {foreground red;puts "FAILED";reset}

#Test the program
eval spawn [lrange $argv 0 end]
send " 3.1400,0.0\r"
expect "false" {foreground green; puts "PASSED";reset} default {foreground red;puts "FAILED";reset}

#Test the program
eval spawn [lrange $argv 0 end]
send " 300,000,100.0e12 \r"
expect "true" {foreground green; puts "PASSED";reset} default {foreground red;puts "FAILED";reset}

#Test the program
eval spawn [lrange $argv 0 end]
send "e9\r"
expect "false" {foreground green; puts "PASSED";reset} default {foreground red;puts "FAILED";reset}

#Test the program
eval spawn [lrange $argv 0 end]
send ".1231\r"
expect "true" {foreground green; puts "PASSED";reset} default {foreground red;puts "FAILED";reset}

#Test the program
eval spawn [lrange $argv 0 end]
send "+45\r"
expect "true" {foreground green; puts "PASSED";reset} default {foreground red;puts "FAILED";reset}

#Test the program
eval spawn [lrange $argv 0 end]
send -- "-45\r"
expect "true" {foreground green; puts "PASSED";reset} default {foreground red;puts "FAILED";reset}

#Test the program
eval spawn [lrange $argv 0 end]
send -- "+45e-10\r"
expect "true" {foreground green; puts "PASSED";reset} default {foreground red;puts "FAILED";reset}

#Test the program
eval spawn [lrange $argv 0 end]
send -- "+45e+-12\r"
expect "false" {foreground green; puts "PASSED";reset} default {foreground red;puts "FAILED";reset}