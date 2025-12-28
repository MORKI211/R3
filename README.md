# R3

> Network-enhanced RPCS3 fork for reverse engineering and custom servers

![License](https://img.shields.io/badge/license-GPLv2-blue)
![Platform](https://img.shields.io/badge/platform-Linux%20%7C%20Windows-lightgrey)
![Status](https://img.shields.io/badge/status-experimental-orange)

## What is R3?

R3 is a modified RPCS3 emulator with enhanced network interception 
capabilities for reverse engineering PS3 online games and developing 
custom servers.

### Key Features

🔓 **SSL/TLS Bypass** - Disable certificate validation  
🔐 **Custom CA Support** - Use your own certificates  
📡 **Traffic Logging** - Capture and analyze all network traffic  
🌐 **DNS Override** - Redirect game servers without hosts file  
⚡ **Zero Game Patching** - Works with unmodified game files  

## Use Cases

- Custom FIFA Ultimate Team servers
- Legacy game preservation  
- Network protocol research
- Educational reverse engineering

## Quick Start
```bash
# Clone
git clone https://github.com/mork/R3
cd R3

# Build (Linux)
./build.sh --enable-network-mods

# Run with SSL bypass
./r3 --disable-ssl-validation \
     --trust-ca ./my-ca.crt \
     --log-network ./traffic.log \
     --game FIFA15.pkg
```

## Configuration

Create `r3_network.yml`:
```yaml
network:
  ssl:
    disable_validation: true
    custom_ca: /path/to/ca.crt
    log_handshakes: true
    
  dns_override:
    "ut.fifa15.ea.com": "127.0.0.1"
    "accounts.ea.com": "192.168.1.100"
    
  logging:
    capture_traffic: true
    output_file: "network_dump.pcap"
```

## Compared to RPCS3

| Feature | RPCS3 | R3 |
|---------|-------|-----|
| PS3 Game Emulation | ✅ | ✅ |
| SSL Certificate Bypass | ❌ | ✅ |
| Custom CA Support | ❌ | ✅ |
| Network Traffic Logging | ❌ | ✅ |
| DNS Override | ❌ | ✅ |
| MITM-Friendly | ❌ | ✅ |

## Upstream Sync

R3 regularly merges from RPCS3 master to stay up-to-date.
```bash
# Sync with upstream
git remote add upstream https://github.com/RPCS3/rpcs3
git fetch upstream
git merge upstream/master
```

## Building

See [BUILD.md](BUILD.md) for detailed instructions.

## Legal

R3 is a fork of RPCS3 (GPLv2). All original credits to RPCS3 team.

**For educational and game preservation purposes only.**  
Respect copyright laws and terms of service.

## Contributing

PRs welcome! See [CONTRIBUTING.md](CONTRIBUTING.md)

## Acknowledgments

- RPCS3 Team - Original emulator
- FIFA Modding Community
- Everyone preserving legacy online games

---

**R3** - When the original isn't enough.
```

---

## Logo ideas dla R3:

### Minimalist:
```
 ██████╗ ██████╗ 
 ██╔══██╗╚════██╗
 ██████╔╝ █████╔╝
 ██╔══██╗ ╚═══██╗
 ██║  ██║██████╔╝
 ╚═╝  ╚═╝╚═════╝ 
```

### Matrix style:
```
[R][3] -> NETWORK_UNLOCK
```

### Simple:
```
R³
```

---

## Social media / Community:

**Discord server:** `R3 Network Mods`  
**Subreddit:** `/r/R3Emulator` (jeśli urośnie)  
**Twitter/X:** `@R3_Emulator`

---

## First release version:
```
R3 v0.1.0-alpha "Handshake"
- SSL validation bypass
- Basic traffic logging
- Upstream sync: RPCS3 v0.0.33-16590

Known issues:
- Some ciphers not supported yet
- GUI settings incomplete
- Linux only (Windows WIP)
