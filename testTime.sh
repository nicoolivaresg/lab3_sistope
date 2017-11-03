readonly limit=10
{ for h in {1..14}; do time for i in {1..10}; do ./wave -N 128 -T 2000 -H $h -f nada.txt -t 2000; done; done; } 2> times/time-128-2000.txt
{ for h in {1..14}; do time for i in {1..10}; do ./wave -N 128 -T 4000 -H $h -f nada.txt -t 4000; done; done; } 2> times/time-128-4000.txt
{ for h in {1..14}; do time for i in {1..10}; do ./wave -N 128 -T 8000 -H $h -f nada.txt -t 8000; done; done; } 2> times/time-128-8000.txt
{ for h in {1..14}; do time for i in {1..10}; do ./wave -N 256 -T 2000 -H $h -f nada.txt -t 2000; done; done; } 2> times/time-256-2000.txt
{ for h in {1..14}; do time for i in {1..10}; do ./wave -N 256 -T 4000 -H $h -f nada.txt -t 4000; done; done; } 2> times/time-256-4000.txt
{ for h in {1..14}; do time for i in {1..10}; do ./wave -N 256 -T 8000 -H $h -f nada.txt -t 8000; done; done; } 2> times/time-256-8000.txt
{ for h in {1..14}; do time for i in {1..10}; do ./wave -N 512 -T 2000 -H $h -f nada.txt -t 2000; done; done; } 2> times/time-512-2000.txt
{ for h in {1..14}; do time for i in {1..10}; do ./wave -N 512 -T 4000 -H $h -f nada.txt -t 4000; done; done; } 2> times/time-512-4000.txt
{ for h in {1..14}; do time for i in {1..10}; do ./wave -N 512 -T 8000 -H $h -f nada.txt -t 8000; done; done; } 2> times/time-512-8000.txt
