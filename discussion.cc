touch runner
vi runner

edit the file
#!/bin/bash
echo "hello"

chmod 755 runner
./runner

-------------------
var=2
var="heloo"

echo $var


-------------------
#!/bin/bash
counter=2
while[ counter - le 1000 ]
do
  ./mergesort $counter
  counter=$(($counter*2))
done

