# C++23 Sample Project using VCPKG

Simple sample project/template project using Microsoft's [vcpkg](https://vcpkg.io/en/) and a Visual Studio Code setup.

Possibly easy to copy-paste from.

I made this because getting this set up was very annoying unlike more popular languages like Java or python and nodejs these days.

### Prerequisites

#### Mandatory

Some package manager. The subsequent commands are based on [brew](https://brew.sh/) (MacOS/Linux).


#### Optional/Recommended

VSCode as the main text editor/IDE:

```sh
brew install --cask visual-studio-code
```

#### Dependencies + Setup

<details>
<summary><b>Base Dependencies (via e.g. Homebrew)</b></summary>

First, install [brew](https://brew.sh/) (MacOS/Linux) or equivalent.


Then, install C++ build tools:

```sh
brew update

# C++ build tools
brew install llvm
brew install cmake
brew install ninja
brew install pkg-config
```

</details>
<br>

<details>
<summary><b>Package Manager - <code>vcpkg</code></b></summary>

This project uses [vcpkg](https://vcpkg.io/en/) for C++ package/dependency management.

Set it up (once per dev machine):
```sh
cd ~/git # or whatever directory you use for git
git clone https://github.com/microsoft/vcpkg.git
cd vcpkg && ./bootstrap-vcpkg.sh
```

To make the `vcpkg` package manager globally available (see also [docs](https://learn.microsoft.com/en-us/vcpkg/get_started/get-started-vscode?pivots=shell-bash#4---set-up-environment-variables)):
```sh
# Let us assume you cloned the repo above into ~/git/vcpkg
VCPKG_REPO_CLONE_PATH=$HOME/git/vcpkg

# Append to end of ~/.zshrc (MacOS)
echo "export VCPKG_ROOT=$VCPKG_REPO_CLONE_PATH" >> ~/.zshrc
echo "export PATH=\$PATH:\$VCPKG_ROOT" >> ~/.zshrc
source ~/.zshrc # after you've made changes

# Append to end of ~/.bashrc (Linux/MacOS)
echo "export VCPKG_ROOT=$VCPKG_REPO_CLONE_PATH" >> ~/.bashrc
echo "export PATH=\$PATH:\$VCPKG_ROOT" >> ~/.bashrc
source ~/.bashrc # after you've made changes

# Test that the package manager works:
vcpkg --version
```

(see also [this guide](https://learn.microsoft.com/en-us/vcpkg/get_started/get-started-vscode?pivots=shell-bash) for setting it up).
</details>
<br>

<details>
<summary><b>Build Automation - CMake</b></summary>

The following setup is needed for Build Automation both via the CLI as well as via the VSCode UI.
See also the docs on the setup [here](https://learn.microsoft.com/en-us/vcpkg/get_started/get-started?pivots=shell-bash).

#### Setup CMake Tools to use `vcpkg`
To make the VSCode UI properly use the `vcpkg` executable,
update and add the following file with your path to the directory of the repo containing `vcpkg` (installed in the section above).

**[Option 1]** Automatically by running this command:

```sh
# Let us assume you cloned the vcpkg repo into ~/git/vcpkg
VCPKG_REPO_CLONE_PATH=$HOME/git/vcpkg

cp ./CMakeUserPresets.json.example ./CMakeUserPresets.json
sed -i "" -e "s#<path to vcpkg>#$VCPKG_REPO_CLONE_PATH#g" ./CMakeUserPresets.json
```

**[Option 2]** Or manually:
1. Copy `./CMakeUserPresets.json.example` to `./CMakeUserPresets.json` (this file is ignored by git)
2. open `./CMakeUserPresets.json` and replace `<path to vcpkg>` with the absolute path to the directory containing the `vcpkg` executable.

</details>
<br>

<details>
<summary><b>Editor + Build Automation Tools - VSCode (Optional)</b></summary>

It's not mandatory to use VSCode, but the project was set up around it.

First, install VSCode for your OS.
Next, install these extensions for working with C++ using VSCode:

```sh
code --install-extension ms-vscode.cpptools
code --install-extension ms-vscode.cmake-tools
```

We will invoke Build Automation commands via the [CMake Tools extension](https://marketplace.visualstudio.com/items/?itemName=ms-vscode.cmake-tools). There's a few ways to do this (including strictly via the terminal but this would require additional setup).

This is very similar to e.g. `maven` for Java (think of `mvn clean compile`, `mvn test`, ...).

See also section "Building" below.

</details>

### Building


<details>
<summary><b>Build via CLI + CMake</b></summary>

If you had existing build input, get rid of it:
```sh
rm -rf build
```

To build, we run:
```sh
mkdir build
# Runs the setup configured in CMakeUserPresets.json with { "name": "default", ... }
cmake --preset=default
# Builds the project
cmake --build build
```

(See also [docs here](https://learn.microsoft.com/en-us/vcpkg/get_started/get-started?pivots=shell-bash#4---build-and-run-the-project))
</details>
<br>

<details>
<summary><b>Build via VSCode + CMake</b></summary>

We invoke Build Automation commands via the [CMake Tools extension](https://marketplace.visualstudio.com/items/?itemName=ms-vscode.cmake-tools).

There's a few ways to do this (including strictly via the terminal but this would require additional setup).

This is very similar to e.g. `maven` for Java (think of `mvn clean compile`, `mvn test`, ...).

TL;DR:


<details>
<summary><b>a. Use VSCode Commands UI (⭐️ Recommended)</b></summary>

You can run the build steps via the UI, similar to how this works e.g. in IntelliJ for Java.

This is recommended due to it's convenience, but you can use whatever setup.

- Use the "`CMake`" tab in the left sidebar of VSCode (should have gotten added by default when you installed the [CMake Tools extension](https://marketplace.visualstudio.com/items/?itemName=ms-vscode.cmake-tools))
- If you want, you can move this extension's UI to the right sidebar by click-dragging to the right on the screen
- Use `Project Status` window and use `Pinned Commands` to pin useful commands like `Clean Rebuild` and `Build`
- You can execute commands by clicking on them in this UI

![Screenshot of the sidebar for the CMake Extension](./docs/2025-04-21_13-38.png)

</details>
<br>

<details>
<summary><b>b. Use VSCode Run Command (MacOS) </b></summary>

You can also run the Build steps via the "Run" bar:

- Invoke the `Run` bar in VSCode via `⌘ (Cmd)` +`⇧ (Shift)` + `P`
- Run CMake commands specific commands by typing `CMake: <Your Action>` in the `Run` bar (because the `Run` bar contains a bunch of stuff from VSCode and form your other extensions too)

</details>
<br>


<details>
<summary><b>c. Others: TODO add equivalent setups/commands</b></summary>

TODO...

</details>
</details>

### Running

After the project has been compiled/built, it is available as a binary in the `./build` output directory.

You can execute it like so:
```sh
./build/HelloWorld
```
