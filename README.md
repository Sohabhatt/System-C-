#  SystemC Design Repository

This repository contains a collection of hardware design modules implemented using **SystemC**, a C++-based modeling language for system-level digital design and simulation.

All designs in this repository are:
- ✅ Written in SystemC  
- 🛠️ Simulated using the SystemC compiler &  
- 📈 Waveforms visualized using GTKWave

---

## 🛠️ Prerequisites

To compile and run the designs, ensure the following tools are installed:

### 🔧 Install SystemC

#### On Linux:
```bash
sudo apt update & sudo apt install build-essential -y
wget https://www.accellera.org/images/downloads/standards/systemc/systemc-2.3.3.tar.gz
tar -xzf systemc-2.3.3.tar.gz & cd systemc-2.3.3
mkdir objdir & cd objdir
../configure --prefix=/usr/local/systemc
make -j$(nproc) & sudo make install

# Reference:
Accellera SystemC Downloads

On Windows:

Use MSYS2 or Cygwin terminal and follow similar steps as Linux:

pacman -Syu & pacman -S make gcc
# Then follow the Linux instructions inside the terminal

📚 Reference: SystemC for Windows (GitHub Guide)
📦 Install GTKWave
On Linux:

sudo apt install gtkwave

On Windows:

Download the installer from:
🌐 http://gtkwave.sourceforge.net
🚀 How to Compile & Simulate
🔨 Compile Example:

g++ -I/usr/local/systemc/include -L/usr/local/systemc/lib-linux -lsystemc module.cpp testbench.cpp -o sim.out
./sim.out

📊 View Waveforms:

gtkwave dump.vcd

📁 Repository Structure

Each design folder includes:

    *.h and *.cpp files for the modules

    A sc_main() testbench

    A dump.vcd waveform output for GTKWave

🤝 Contributing

Found a bug or want to add a new module?
Fork the repo & submit a pull request. Contributions are welcome!
📜 License

This repository is licensed under the MIT License. See LICENSE for details.
📬 Contact

For questions, suggestions, or collaboration ideas, feel free to open an issue or discussion.


Let me know if you want me to:
- Generate a sample SystemC module structure (`adder`, `mux`, etc.)
- Add a sample `.gitignore` file for SystemC
- Include a `CMakeLists.txt` for easier build automation
