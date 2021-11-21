#!/usr/bin/expect -f

# https://likegeeks.com/expect-command/

set timeout -1
set DONE 0

spawn ./questions.sh

while { $DONE == 0 } {

  expect {

      "*topic?" { send -- "Programming\r" }

      "*movie?" { send -- "Star Wars\r" }

      eof { set DONE 1 }

  }

}
