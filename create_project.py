import sys
from pathlib import Path


args_num = len(sys.argv)
if args_num != 3:
    print("error: invalid number of arguments.")
    print("The arguments you entered are here:",
          sys.argv[1:],
          ". The expected arguments are \"<chapter name>\" and \"<project name>\".")
    exit(1)

chapter_name = sys.argv[1]
project_name = sys.argv[2]

if not chapter_name.startswith("chapter"):
    print("error: <chapter name> should have prefix `chapter`.")
    print("The chapter name you entered is here:", chapter_name)
    exit(1)

if not (project_name.startswith("code") or project_name.startswith("practice")):
    print("error: <project name> should have prefix `code` or `practice`.")
    print("The project name you entered is here:", project_name)
    exit(1)

cur_dir = Path.cwd()
chapter_dir = cur_dir / chapter_name
project_dir = chapter_dir / project_name

if not chapter_dir.exists():
    chapter_dir.mkdir()

while not chapter_dir.exists():
    pass

if not project_dir.exists():
    project_dir.mkdir()

while not project_dir.exists():
    pass

# cppファイルのパスと雛形
cpp_path = project_dir / (project_name + ".cpp")
cpp_content = "#include <iostream>\n#include <vector>\n"

# Makefileのパスと内容
makefile_path = project_dir / "Makefile"
makefile_content = "CXXFLAGS = -std=c++11\n\n"\
    + project_name + ": " + project_name + ".cpp\n\n"\
    + "run: " + project_name + "\n\t./$<\n\n"\
    + "clean:\n\t-rm " + project_name + "\n\n"\
    + ".PHONY: clean\n"

# .gitignoreのパスと内容
gitignore_path = project_dir / ".gitignore"
gitignore_content = project_name + "\n"

# ファイルの作成
with cpp_path.open('w') as f:
    f.write(cpp_content)

with makefile_path.open('w') as f:
    f.write(makefile_content)

with gitignore_path.open('w') as f:
    f.write(gitignore_content)

print("complete!")

