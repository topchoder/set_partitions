# set_partitions
In this we will generate k partitions of a set(need not to be contiguos).
It is different from the conventional partitions in which generate all contiguos partitions.
we will need to use the diffrent way this time,for each element of array either it will form a new partition(if number of partitions still less than k),else we will put it any previous of k partition only one at time,so this recurrence relation is normally called stirling number of second kind.
