#/bin/bash

# # 1. WAP to check whether a number is amstrong or not.

# echo "Enter a number"
# read num
# n=$num
# sum=0
# while [ $num -gt 0 ]
# do
#     r=`expr $num % 10`
#     sum=`expr $sum + $r \* $r \* $r`
#     num=`expr $num / 10`
# done

# if [ $n -eq $sum ]
# then
#     echo "Amstrong number"
# else
#     echo "Not an amstrong number"
# fi

# # 2. Find the sum of 1! 2!.... n! using single loop

# echo "Enter a number"
# read n
# fact=1
# sum=0
# for (( i=1; i<=n; i++ ))
# do
#     fact=`expr $fact \* $i`
#     sum=`expr $sum + $fact`
# done

# echo "Sum of 1! 2!.... n! is $sum"

# # 3. WAP to find the number, if the factorial is given

# echo "Enter a number"
# read n
# fact=1
# i=1
# while [ $fact -lt $n ]
# do
#     i=`expr $i + 1`
#     fact=`expr $fact \* $i`
# done

# if [ $fact -eq $n ]
# then
#     echo "The number is $i"
# else
#     echo "The number is not found"
# fi

# # 4. WAP to find the nth fibonacci number

# echo "Enter a number"
# read n
# a=0
# b=1
# i=2
# while [ $i -lt $n ]
# do
#     c=`expr $a + $b`
#     a=$b
#     b=$c
#     i=`expr $i + 1`
# done

# echo "The $n th fibonacci number is $c"

# 5. WAP to print a pattern

echo "Enter a number"
read n
for (( i=1; i<=n; i++ ))
do
    for (( j=1; j<=n-i; j++ ))
    do
        echo -n " "
    done
    for (( j=1; j<=i; j++ ))
    do
        echo -n "* "
    done
    echo
done
