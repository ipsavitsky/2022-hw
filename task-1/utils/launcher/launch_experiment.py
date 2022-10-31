import subprocess
import itertools
import time
import csv

proc_sizes = range(100, 700, 100)
task_amounts = range(30000, 38000, 1000)

experiments = []
for procs, tasks in itertools.product(proc_sizes, task_amounts):
    subprocess.run(["python3", "../generator/generator.py", str(procs), str(tasks), str(tasks*3), "res.csv"])
    times_list = []
    for n in range(5):
        print(f"running test {n+1} on proc={procs}, tasks={tasks}")
        st = time.time()
        subprocess.run(["../../build/sched", "res.csv", str(procs), "10"])
        en = time.time()
        times_list.append(en-st)
    experiments.append([procs, tasks, sum(times_list)/len(times_list)])

with open("out.csv", "w", newline="") as outfile:
    wrtr = csv.writer(outfile)
    wrtr.writerows(experiments)
