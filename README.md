# Unistra L2S3 SDA Final Exam 


<div align="center">
  <img src="https://i.imgur.com/JXhyQn1.png" alt="Figure1" width="80%"/>
      <p style="font-size:small;">[Figure 1]</p>
  <img src="https://i.imgur.com/Fmbvj4l.png" alt="Figure2" width="70%"/>
      <p style="font-size:small;">[Figure 2]</p>
</div>

## Launch 🔌
```
% git@github.com:SitaraLiang/Unistra-L2S3-SDA-FINAL-EXAM.git
```


```
% make
```
```
% ./main
```

## Description

In a standard linked list, a significant portion of memory is used for chaining management. A solution to optimize memory space is to use a block data structure, that is to say that each link in the List stores several elements as illustrated above (Figure1).

When you want to add an element to an already full block, you must cut the block into two blocks to then add it to the correct block. The above (Figure2) illustrates the operation of cutting a block.

## Preconditions

- The circular doubly linked list must be sorted at all times.

- The search operation in a table must take into account the fact that the table is sorted and ideally carried out by a dichotomous search in the table.

