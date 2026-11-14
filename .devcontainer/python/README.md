# Python Codespace

In GitHub, choose **Code > Codespaces > ... > New with options**, select
**Python** as the dev container configuration, and create the Codespace.
In VS Code, run **Dev Containers: Reopen in Container** and choose **Python**.

The container includes Python 3.14, pip, setuptools, wheel, pytest, Ruff,
Git, and Git LFS. VS Code has Python completion, debugging, test discovery,
and formatting on save enabled.

A virtual environment at `/home/vscode/.venv` is created automatically and
selected for the editor and terminal. Install your exercise's dependencies
there, for example:

```bash
python -m pip install -r path/to/requirements.txt
```

Run these commands from the directory containing your Python code:

```bash
python main.py
python -m pytest
```

Rebuilding the container recreates the virtual environment. Keep project
dependencies in a requirements file or `pyproject.toml` so you can reinstall them.
