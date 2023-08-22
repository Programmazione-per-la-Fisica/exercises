# Central limit theorem
The central limit theorem says that if we have a set of N random variables sampled from the same distribution, with finite mean and variance, as N goes to infinity their average is going to be a random variable distributed according to a gaussian (see https://en.wikipedia.org/wiki/Central_limit_theorem).
Write a function that samples random variables and calculate their averages, and then repeat the process many times to observe the resulting distribution. If would be useful to plot the data to observe this distribution, do it using a method of your choice (ROOT, python, gnuplot, excel,...). 

(In the solution you just have to execute the exec.sh script and the plot will automatically appear)

To execute the plotting script you need Python. You can install python simply with:
```
    sudo apt install python3 (on Ubuntu)
```
Then you need the matplotlib package. To install it you need the package manager for Python, pip:
```
    sudo apt install python3-pip
```
and then we can use `pip3` to install the packages. We need the packages `matplotlib` and `pandas`:
```
    pip3 install matplotlib
    pip3 install pandas
```
