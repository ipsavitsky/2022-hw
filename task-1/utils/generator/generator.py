import csv
import argparse
import random

parser = argparse.ArgumentParser()
parser.add_argument("n_procs", type=int)
parser.add_argument("n_tasks", type=int)
parser.add_argument("stop_time", type=int)
parser.add_argument("output_filename", type=str)
args = parser.parse_args()


def split_task(
    task_to_split: tuple[int, int]
) -> tuple[tuple[int, int], tuple[int, int]]:
    q = random.randrange(task_to_split[0], task_to_split[1])
    return (task_to_split[0], q), (q, task_to_split[1])


# n_procs = args.n_procs
# n_tasks = args.n_tasks
# stop_time = a
# # schedule = [[(0, stop_time)]] * n_procs
# output_filename = "res.csv"

schedule = []
for i in range(args.n_procs):
    schedule.append([(0, args.stop_time)])

for i in range(args.n_tasks - 1):
    while True:
        num_proc = random.randrange(0, args.n_procs)
        task_to_split = random.randrange(0, len(schedule[num_proc]))
        fr, to = schedule[num_proc][task_to_split]
        if to - fr > 1:
            break
    result_tasks = split_task(schedule[num_proc][task_to_split])
    # print("result task ", result_tasks)
    schedule[num_proc][task_to_split] = result_tasks[0]
    schedule[num_proc].insert(task_to_split + 1, result_tasks[1])


task_times = []
for proc in schedule:
    for fr, to in proc:
        task_times.append(to - fr + 1)

with open(args.output_filename, "w") as f:
    sched_writer = csv.writer(f)
    sched_writer.writerow(task_times)
