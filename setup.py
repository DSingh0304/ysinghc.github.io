import subprocess as sbp

sbp.run(["sudo", "apt", "install", "git", "-y"])
sbp.run(["git", "clone", "https://github.com/ysinghc/ysinghc.github.io.git"])