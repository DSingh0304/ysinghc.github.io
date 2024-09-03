import subprocess as sbp

sbp.run(["sudo", "apt", "install", "git", "-y"])
sbp.run(["git", "clone", "https://github.com/ysinghc/ysinghc.github.io.git"])
sbp.run(["git", "config", "--global", "user.name", "\"klarab\""])
sbp.run(["git", "config", "--global", "user.email", "\"imv-in\""])

