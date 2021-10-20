for i in {1..10}; do
     echo -ne Testing $i
     sleep .5
     echo -ne .
     sleep .5
     echo -ne .
     sleep .5
     echo .
     echo -ne "Result = "
     if !((i%15)); then echo FizzBuzz
     elif !((i%3)); then echo Fizz
     elif !((i%5)); then echo Buzz
     else echo $i
     fi
     sleep 1
done
