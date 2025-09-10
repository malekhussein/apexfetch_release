# ApexFetch 🖥️✨

A lightweight system information tool for Linux, inspired by **Neofetch**, written in **C++**.  
Displays your system info **next to an ASCII logo** in your terminal.

```
        /\        
       /  \   _ __ 
      / /\ \ | '_ \
     / ____ \| | | |
    /_/    \_\_| |_|
```

---

## 🌟 Features
- Displays:
  - 🐧 OS
  - 💻 Kernel
  - 🏷️ Hostname & Username
  - ⏱️ Uptime
  - 🧠 CPU
  - 🖴 Memory
  - 🐚 Shell
  - 🖥️ Terminal
  - 📦 Packages installed
- ASCII logo displayed next to system info
- Fully written in **C++17**
- Works on Linux (tested on Arch Linux)

---

## 📸 Screenshot
```
       /\        
      /  \   _ __ 
     / /\ \ | '_ \
    / ____ \| | | |
   /_/    \_\_| |_|

OS: Arch Linux
Host: user (user)
Kernel: 6.16.5-arch1-1
Uptime: 2h 30m
CPU: Intel(R) Core(TM) i7-4702MQ CPU @ 2.20GHz (8 cores)
Memory: 4500MiB / 7816MiB
Shell: zsh
Terminal: kitty
Packages: 1342
```

---

## 🚀 Installation

1. **Clone the repository**
```bash
git clone https://github.com/malekhussein/apexfetch_release.git
cd apexfetch
```

2. **Build**
```bash
make
```

3. **Run**
```bash
./apexfetch
```

---

## 📦 Optional: Install system-wide
```bash
sudo cp apexfetch /usr/local/bin/
apexfetch
```

---

## 🛠️ Dependencies
- `g++` with **C++17 support**
- Linux system with `/proc` filesystem

---

## 🎨 Customize ASCII Logo
- Create a file `arch.txt` in the repo folder with your custom ASCII logo.  
- If no file exists, a default logo will be used.

---

## 🔖 Version
This is the **official release** of ApexFetch ✅  
Check out the **first beta version** here: [ApexFetch Beta](https://github.com/malekhussein/apexfetch_beta)

