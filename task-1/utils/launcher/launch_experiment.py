import subprocess
import itertools
import time
import csv

proc_sizes = [400]
task_amounts = [34000]

experiments = []
for procs, tasks in itertools.product(proc_sizes, task_amounts):
    subprocess.run(["python3", "../generator/generator.py", str(procs), str(tasks), str(tasks*3), "res.csv"])
    for n in [1, 2, 4, 8, 16]:
        print(f"running test {n+1} on proc={procs}, tasks={tasks}, threads")
        st = time.time()
        subprocess.run(["../../build/sched", "res.csv", str(procs), "10", str(n)])
        en = time.time()
        experiments.append([procs, tasks, en-st, n])

with open("out_parall.csv", "w", newline="") as outfile:
    wrtr = csv.writer(outfile)
    wrtr.writerow(["procs", "tasks", "time", "n"])
    wrtr.writerows(experiments)
