import subprocess

for i in range(1, 10):
    subprocess.run("git mv lab"+str(i)+" lab0"+str(i), shell=True)