# 🧠 SystemC Design Repository

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
