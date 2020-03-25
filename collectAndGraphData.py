"""
# Author: Richard A. Kell

# File: collectAndGraphData.py
# Desc: Used to run parallel merge sort, collect
# run times, and visualize the collected data
# which is then exported to runTimeGraph.png
"""

import subprocess
from math import log2, ceil
import matplotlib.pyplot as plt

def main():
    # set the number of times to run and then average each number of threads
    numberOfTimesToRun = 3
    
    # run the executable and pass it array size and maxThreads
    subprocessArgs = ["./sort", "800000000", ""]
    
    # list to hold maxThreads for each run
    listOfMaxThreads = []
    # list to hold the average run time of each thread number execution
    averageRunTimes = []

    # compile the parallel merge sort program using the make file
    try:
        # check to see if the binary is already compiled
        subprocess.check_call(
            ["ls", f"{subprocessArgs[0]}"], stdout=subprocess.DEVNULL, stderr=subprocess.DEVNULL
            )
    except subprocess.CalledProcessError:
        subprocess.run("make")

    # run for ~every level up to 1/4 the height of the binary tree
    # using the top 1/4 to prevent throwing error from too many threads 
    for i in range(1, ceil(log2(int(subprocessArgs[1])) / 4) + 1):
        # generate a maxThreads value that will matter algorithmically
        maxThreads = 2**i - 2
        print(f"running with {maxThreads} maxThreads...")
        subprocessArgs[2] = str(maxThreads)
        sum = 0
        for _ in range(numberOfTimesToRun):
            # run the compiled parallel merge sort binary and add the runtime output in seconds format
            sum += float(subprocess.check_output(subprocessArgs, encoding="utf-8").split('s')[0])

        listOfMaxThreads.append(str(maxThreads))
        averageRunTimes.append(sum / numberOfTimesToRun)

    with open("collected_data.txt", 'w') as f:
        f.write(f"listOfMaxThreads: {listOfMaxThreads}\n")
        f.write(f"averageRunTimes: {averageRunTimes}\n")

    # plot, visualize, label, and export the data
    plt.scatter(listOfMaxThreads, averageRunTimes)
    plt.title("The Affect of Maximum Number of Threads on Run Time")
    plt.xlabel("Maximum Number of Threads")
    plt.ylabel("Time in Seconds")
    plt.savefig("runTimeGraph.png", bbox_inches="tight")
    plt.show()

if __name__ == "__main__":
    main()
