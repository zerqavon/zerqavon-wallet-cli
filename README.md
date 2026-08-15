# Zerqavon Core

Official source code for the Zerqavon daemon, command-line wallet and wallet RPC.

Zerqavon (`ZQVX`) is an independent proof-of-work network derived from Monero v0.18.5.1 and adapted for the Zerqavon network. Original CryptoNote and Monero copyright notices remain in the source tree.

## Official links

- Website: https://zerqavon.org
- Block explorer: https://explorer.zerqavon.org
- CLI and daemon: https://github.com/zerqavon/zerqavon-wallet-cli
- GUI wallet: https://github.com/zerqavon/zerqavon-wallet-gui
- CPU miner: https://github.com/zerqavon/miner

## Included programs

- `zerqavond`: full node and daemon RPC
- `zerqavon-wallet-cli`: command-line wallet
- `zerqavon-wallet-rpc`: wallet RPC service
- `zerqavon-blockchain-import`: blockchain import utility
- `zerqavon-blockchain-export`: blockchain export utility

## Clone the correct repository

Clone Zerqavon recursively so all required submodules are downloaded:

```bash
git clone --recursive https://github.com/zerqavon/zerqavon-wallet-cli.git
cd zerqavon-wallet-cli
```

If the repository was cloned without `--recursive`, initialize it with:

```bash
git submodule sync --recursive
git submodule update --init --recursive
```

The public development branch is `main`:

```bash
git checkout main
git pull --ff-only origin main
git submodule update --init --recursive
```

Do not use Monero's `v0.18.5.1` tag with this repository. That tag identifies the upstream codebase from which Zerqavon was derived, not a Zerqavon release. When Zerqavon publishes versioned tags, they will appear on the repository's **Tags** and **Releases** pages.

## Build on Ubuntu or Debian

Install the common build dependencies:

```bash
sudo apt update
sudo apt install -y \
  build-essential cmake pkg-config git ccache \
  libboost-all-dev libssl-dev libzmq3-dev libsodium-dev \
  libunbound-dev liblzma-dev libreadline-dev libexpat1-dev \
  libusb-1.0-0-dev libhidapi-dev libprotobuf-dev protobuf-compiler
```

Build from the repository root:

```bash
make -j"$(nproc)"
```

For the release target used by the project:

```bash
make release -j"$(nproc)"
```

The resulting executables are normally placed under:

```text
build/release/bin/
```

The published Linux build is validated on Ubuntu 26.04 x86-64. Other distributions may require dependency or toolchain adjustments.

## Build on Windows

The Windows build uses an MSYS2/MinGW-w64 toolchain. Open the 64-bit MinGW shell, install the required C++/CMake dependencies, then clone the same Zerqavon repository:

```bash
git clone --recursive https://github.com/zerqavon/zerqavon-wallet-cli.git
cd zerqavon-wallet-cli
make release-static-win64 -j"$(nproc)"
```

Do not clone `monero-project/monero` and do not change into a directory named `monero`; those commands build upstream Monero rather than Zerqavon.

## Run a node

Start the daemon interactively:

```bash
./build/release/bin/zerqavond
```

Useful daemon commands include:

```text
status
print_height
print_cn
exit
```

## Create or open a CLI wallet

Start the wallet against a local daemon:

```bash
./build/release/bin/zerqavon-wallet-cli --daemon-address 127.0.0.1:27771
```

Follow the prompts to create a new wallet or open an existing wallet file. Keep the mnemonic seed, wallet password and `.keys` file private. Never commit wallet files or keys to Git.

## Default data locations

- Linux: `~/.zerqavon/`
- Windows: `C:\ProgramData\zerqavon\`

Wallet files are stored wherever the user chooses when creating or opening a wallet. They are not stored in the source repository by default.

## Updating an existing clone

```bash
cd zerqavon-wallet-cli
git checkout main
git pull --ff-only origin main
git submodule sync --recursive
git submodule update --init --recursive
```

Rebuild after updating:

```bash
make -j"$(nproc)"
```

## Security

- Never reuse Zerqavon wallet keys on Monero or another fork.
- Never publish mnemonic seeds, private keys, wallet `.keys` files or RPC credentials.
- Verify release checksums before running downloaded binaries.
- Back up the mnemonic seed offline before receiving funds.

Security-sensitive reports should not include private keys or live wallet files in a public GitHub issue.

## License and upstream attribution

See [LICENSE](LICENSE) for the applicable BSD 3-Clause terms. Zerqavon is based on upstream Monero/CryptoNote code; the original notices and contributor attribution are preserved in the relevant files.

