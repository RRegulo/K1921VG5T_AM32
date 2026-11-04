FROM mcr.microsoft.com/devcontainers/base:ubuntu-24.04

USER root

RUN apt-get update && apt-get install -y --no-install-recommends \
    build-essential \
    ca-certificates \
    cmake \
    git \
    ninja-build \
    python3 \
    wget \
    libusb-1.0-0 \
    libhidapi-hidraw0 \
    libjaylink0 \
    && rm -rf /var/lib/apt/lists/*

# RISC-V GCC 14.2.0-3 includes the rv32imafc_zicsr_zifencei/ilp32f multilib
# required by K1921VG5T, together with riscv-none-elf-gdb.
RUN wget -qO /tmp/riscv-gcc.tar.gz \
        "https://github.com/xpack-dev-tools/riscv-none-elf-gcc-xpack/releases/download/v14.2.0-3/xpack-riscv-none-elf-gcc-14.2.0-3-linux-x64.tar.gz" && \
    echo "f574415b63f12b09bdd3475223ab492a465d23810646c90c13a4c3b676c83503  /tmp/riscv-gcc.tar.gz" | sha256sum -c - && \
    mkdir -p /opt/riscv-none-elf && \
    tar -xzf /tmp/riscv-gcc.tar.gz --strip-components=1 -C /opt/riscv-none-elf && \
    rm /tmp/riscv-gcc.tar.gz

# OpenOCD from NIIET contains the k1921vg5t flash driver. Its archive does not
# contain the interface scripts, so they are installed from the public SDK.
RUN wget -qO /tmp/openocd-niiet.tar.gz \
        "https://gitflic.ru/project/niiet/openocd/release/4a4e7431-0990-455c-9a8b-487bc98f72f8/87bb57bf-b4d3-4ce4-8f0b-85bb685facbb/download" && \
    echo "549c6dc9e583a4c245c7dcffea3c07b69ac9c63c8ec5cf2daa9b141b089d8bb5  /tmp/openocd-niiet.tar.gz" | sha256sum -c - && \
    mkdir -p /opt/openocd-niiet && \
    tar -xzf /tmp/openocd-niiet.tar.gz --strip-components=1 -C /opt/openocd-niiet && \
    rm /tmp/openocd-niiet.tar.gz && \
    chmod +x /opt/openocd-niiet/bin/openocd && \
    git clone --depth 1 https://gitflic.ru/project/niiet/k1921vg5t_sdk.git /tmp/vg5t-sdk && \
    mkdir -p /opt/openocd-niiet/share/openocd/scripts && \
    cp -r /tmp/vg5t-sdk/tools/openocd/scripts/. /opt/openocd-niiet/share/openocd/scripts/ && \
    rm -rf /tmp/vg5t-sdk

# Current K1921VG5T silicon reports CHIPID 0x4e4c300. The released OpenOCD
# binary compares against 0x4e4c400, so correct both comparisons in the
# supplied binary while building the container.
RUN python3 -c "p='/opt/openocd-niiet/bin/openocd'; d=open(p,'rb').read(); a=bytes.fromhex('81 fa 00 c4 e4 04'); b=bytes.fromhex('81 fa 00 c3 e4 04'); assert d.count(a)==2; open(p,'wb').write(d.replace(a,b))"

ENV PATH=/opt/riscv-none-elf/bin:/opt/openocd-niiet/bin:${PATH}
ENV OPENOCD_SCRIPTS=/opt/openocd-niiet/share/openocd/scripts

USER vscode
