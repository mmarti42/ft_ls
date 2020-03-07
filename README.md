# ft_ls

To recode ls and some of its options allow to find out **how to interact with
the file system using C.**

Improving skills:

> Imperative programming

> Unix

> Algorithms & AI

### Installation

```
$ git clone https://github.com/Kugumi/ft_ls.git
$ cd ft_ls
$ make
```

### Syntax

```
./ft_ls [-lRart] args
```

### Options
|        |        |
| ------ | ------ |
| -l | Lists in long format. |
| -R | Recursively lists subdirectories encountered. |
| -a | Lists all entries, including those that begin with a dot (.), which are normally not listed. |
| -r | Reverses the order of sort to get reverse alphabetic, oldest first, or smallest file size first as appropriate. |
| -t | Sorts by time stamp (latest first) instead of by name. The default is the last modification time. |
