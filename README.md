<div align="center">

```
 ██████╗ ██████╗
 ██╔══██╗╚════██╗
 ██████╔╝ █████╔╝
 ██╔══██╗ ╚═══██╗
 ██║  ██║██████╔╝
 ╚═╝  ╚═╝╚═════╝
```

# R3

### *Network-Enhanced RPCS3 Fork*

**Reverse Engineering • Custom Servers • Network Analysis**

[![License](https://img.shields.io/badge/license-GPLv2-blue.svg)](LICENSE)
[![Platform](https://img.shields.io/badge/platform-Windows%20%7C%20Linux-lightgrey.svg)]()
[![Status](https://img.shields.io/badge/status-experimental-orange.svg)]()
[![Based on RPCS3](https://img.shields.io/badge/based%20on-RPCS3-0078D6.svg)](https://github.com/RPCS3/rpcs3)

[Features](#-features) • [Installation](#-installation) • [Usage](#-usage) • [Contributing](#-contributing) • [Legal](#-legal)

</div>

---

## ⚠️ **IMPORTANT NOTICE**

> **Want to play PS3 games? Use [RPCS3](https://rpcs3.net/) instead!**
>
> R3 is **NOT** designed for regular gaming. This fork is a **specialized tool** for:
> - 🔬 **Network protocol reverse engineering**
> - 🛠️ **Creating custom servers for discontinued games**
> - 📚 **Educational security research**
> - 🏛️ **Game preservation projects**
>
> **If you want the best PS3 emulation experience, use mainline RPCS3.**
> R3 sacrifices security features for research capabilities.

---

## 🎯 What is R3?

R3 is a modified RPCS3 emulator that **removes SSL/TLS certificate validation** and adds **powerful network interception tools**. This makes it possible to:

- **Resurrect dead online games** by creating custom servers
- **Capture and analyze** encrypted game traffic
- **Modify network behavior** without patching game files
- **Research network protocols** of legacy PS3 games

### Why R3 exists

Many beloved PS3 online games have shut down their servers forever. R3 gives researchers and preservationists the tools to bring these games back to life through custom server implementations.

---

## ✨ Features

<table>
<tr>
<td width="50%">

### 🔓 Network Modifications

- **SSL/TLS Certificate Bypass**
  Disable validation for MITM analysis

- **Custom CA Support**
  Trust your own certificate authorities

- **DNS Override System**
  Redirect servers without modifying hosts file

</td>
<td width="50%">

### 📡 Research Tools

- **Traffic Logging**
  Capture all network activity to PCAP

- **Protocol Analysis**
  Log SSL handshakes and payloads

- **Zero Game Patching**
  Works with unmodified game files

</td>
</tr>
</table>

---

## 📊 R3 vs RPCS3

| Feature | RPCS3 | R3 |
|---------|:-----:|:--:|
| **PS3 Game Emulation** | ✅ Excellent | ✅ Same core |
| **Performance** | ✅ Optimized | ✅ Same |
| **Compatibility** | ✅ 2000+ games | ✅ Inherited |
| **SSL Security** | ✅ Secure | ⚠️ **Disabled** |
| **Certificate Validation** | ✅ Enforced | ❌ **Bypassed** |
| **Network Interception** | ❌ | ✅ **Full MITM** |
| **Custom CA Support** | ❌ | ✅ |
| **DNS Override** | ❌ | ✅ |
| **Traffic Logging** | ❌ | ✅ **PCAP export** |
| **Recommended for gaming** | ✅ **YES** | ❌ **NO** |
| **Recommended for research** | ❌ | ✅ **YES** |

**🎮 For gaming:** Use [RPCS3](https://rpcs3.net/)
**🔬 For research:** Use R3

---

## 🚀 Installation

### Prerequisites

Same as RPCS3:
- Windows 10/11 (64-bit) or Linux
- Vulkan-compatible GPU
- 4+ GB RAM
- PS3 firmware files

### Building from Source

```bash
# Clone repository
git clone https://github.com/MORKI211/R3.git
cd R3

# Initialize submodules
git submodule update --init --recursive

# Build (see BUILDING.md for detailed instructions)
cmake -B build -DCMAKE_BUILD_TYPE=Release
cmake --build build --config Release
```

See [BUILDING.md](BUILDING.md) for platform-specific instructions.

---

## 💡 Usage

### Example: Custom Server for Dead Game

```bash
# 1. Set up your custom server
./r3 --disable-ssl-validation \
     --custom-ca ./certs/my-ca.crt \
     --dns-override "game-server.ea.com:127.0.0.1" \
     --log-network ./traffic.pcap

# 2. Game connects to YOUR server instead of (dead) official one
# 3. Analyze captured traffic to understand protocol
# 4. Implement server responses
# 5. Resurrect the game! 🎮
```

### Configuration File

Create `r3_network.yml` in your config directory:

```yaml
network:
  ssl:
    disable_validation: true      # Allow self-signed certs
    custom_ca: ./certs/ca.crt     # Your CA certificate
    log_handshakes: true          # Debug SSL connections

  dns_override:
    "matchmaking.game.com": "192.168.1.100"
    "auth.game.com": "192.168.1.100"

  logging:
    enabled: true
    output_format: pcap           # Wireshark-compatible
    output_file: ./captures/traffic.pcap
    log_plaintext: true           # Log decrypted traffic
```

---

## 🎯 Use Cases

### ✅ Legitimate Uses

- **Game Preservation**: Restore online functionality to discontinued games
- **Security Research**: Study network security in legacy software
- **Education**: Learn about network protocols and reverse engineering
- **Custom Servers**: Build community servers for abandoned games

### ❌ Don't Use R3 For

- Playing games with active official servers
- Cheating or exploiting online games
- Violating terms of service
- Any illegal activities

---

## 🔄 Staying Updated

R3 regularly syncs with upstream RPCS3 to inherit improvements:

```bash
# Add upstream RPCS3 as remote
git remote add upstream https://github.com/RPCS3/rpcs3.git

# Fetch and merge latest changes
git fetch upstream
git merge upstream/master
```

Current upstream sync: **RPCS3 v0.0.33** (update this after syncing)

---

## 🤝 Contributing

Contributions welcome! This project needs:

- 🔧 Network stack improvements
- 📝 Documentation for custom server development
- 🧪 Testing on various games
- 🌐 Protocol documentation

See [CONTRIBUTING.md](CONTRIBUTING.md) for guidelines.

---

## 📜 Legal

### License

R3 is licensed under **GPLv2**, same as RPCS3.
All original RPCS3 credits go to the [RPCS3 Team](https://github.com/RPCS3/rpcs3/graphs/contributors).

### Disclaimer

⚖️ **For educational and game preservation purposes only.**

- Respect copyright laws and game publishers' intellectual property
- Do not use R3 to violate terms of service
- This tool is for **research and preservation**, not piracy or cheating
- Users are responsible for their own actions

### Ethics

We believe in **game preservation**. When official servers shut down, games shouldn't be lost forever. R3 exists to help dedicated communities keep their favorite games alive through custom servers.

---

## 🙏 Acknowledgments

- **[RPCS3 Team](https://rpcs3.net/)** - For creating an incredible PS3 emulator
- **Game Preservation Community** - For keeping legacy games alive
- **Security Researchers** - For advancing network analysis tools
- **Contributors** - Everyone who helps improve R3

---

## 📞 Community

- **Issues**: [GitHub Issues](https://github.com/MORKI211/R3/issues)
- **Discussions**: [GitHub Discussions](https://github.com/MORKI211/R3/discussions)

> **Note**: This is an early-stage project. Features are experimental and may not work perfectly.

---

<div align="center">

**R3** • *Because every game deserves a second chance*

Made with 🔬 for the game preservation community

[⬆ Back to Top](#r3)

</div>
