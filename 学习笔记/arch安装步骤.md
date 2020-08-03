用 vim 替代 vi
创建一个alias，如下：

alias vi=vim







终端下显示主机信息

sudo pacman -S neofetch

终端默

vim ～/.bashrc                 文件下加入

neofetch



startx 启动 dwm桌面







Arch 安装

校准时间

```
timedatectl set-ntp true
```

设置中国源优先

```
vim /etc/pacman.d/mirrorlist
```

分区   格式化   挂在分区

安装基础文件

```
pacstrap /mnt base linux linux-firmware base-devel dhcpcd
```

生成链接诶

```
genfstab -U /mnt >>/mnt/etc/fstab 

```





# 安装指南

[跳转到导航](https://wiki.archlinux.org/index.php/Installation_guide#mw-head)[跳转到搜索](https://wiki.archlinux.org/index.php/Installation_guide#p-search)

本文档是从正式安装映像启动的实时系统中安装[Arch Linux](https://wiki.archlinux.org/index.php/Arch_Linux)的指南。在安装之前，建议先查看[FAQ](https://wiki.archlinux.org/index.php/FAQ)。有关本文档中使用的约定，请参见[Help：Reading](https://wiki.archlinux.org/index.php/Help:Reading)。特别是，代码示例可能包含`*italics*`必须手动替换的占位符（格式为）。

有关更多详细说明，请参见本指南链接的相应[ArchWiki](https://wiki.archlinux.org/index.php/ArchWiki)文章或各种程序的[手册页](https://wiki.archlinux.org/index.php/Man_page)。对于交互式帮助，还提供了[IRC频道](https://wiki.archlinux.org/index.php/IRC_channel)和[论坛](https://bbs.archlinux.org/)。

Arch Linux应该可以在任何具有[x86_64](https://en.wikipedia.org/wiki/X86-64)兼容性的计算机上运行，并且至少具有512 MiB RAM。基本安装应占用少于800 MiB的磁盘空间。由于安装过程需要从远程存储库检索软件包，因此本指南假定可以使用正常的Internet连接。

## 内容



- 1预安装
  - [1.1验证签名](https://wiki.archlinux.org/index.php/Installation_guide#Verify_signature)
  - [1.2启动实时环境](https://wiki.archlinux.org/index.php/Installation_guide#Boot_the_live_environment)
  - [1.3设置键盘布局](https://wiki.archlinux.org/index.php/Installation_guide#Set_the_keyboard_layout)
  - [1.4验证启动模式](https://wiki.archlinux.org/index.php/Installation_guide#Verify_the_boot_mode)
  - [1.5连接到互联网](https://wiki.archlinux.org/index.php/Installation_guide#Connect_to_the_internet)
  - [1.6更新系统时钟](https://wiki.archlinux.org/index.php/Installation_guide#Update_the_system_clock)
  - 1.7磁盘分区
    - [1.7.1示例布局](https://wiki.archlinux.org/index.php/Installation_guide#Example_layouts)
  - [1.8格式化分区](https://wiki.archlinux.org/index.php/Installation_guide#Format_the_partitions)
  - [1.9挂载文件系统](https://wiki.archlinux.org/index.php/Installation_guide#Mount_the_file_systems)
- 2安装
  - [2.1选择后视镜](https://wiki.archlinux.org/index.php/Installation_guide#Select_the_mirrors)
  - [2.2安装基本软件包](https://wiki.archlinux.org/index.php/Installation_guide#Install_essential_packages)
- 3配置系统
  - [3.1Fstab](https://wiki.archlinux.org/index.php/Installation_guide#Fstab)
  - [3.2Chroot](https://wiki.archlinux.org/index.php/Installation_guide#Chroot)
  - [3.3时区](https://wiki.archlinux.org/index.php/Installation_guide#Time_zone)
  - [3.4本地化](https://wiki.archlinux.org/index.php/Installation_guide#Localization)
  - [3.5网络配置](https://wiki.archlinux.org/index.php/Installation_guide#Network_configuration)
  - [3.6初始化文件](https://wiki.archlinux.org/index.php/Installation_guide#Initramfs)
  - [3.7根密码](https://wiki.archlinux.org/index.php/Installation_guide#Root_password)
  - [3.8引导程序](https://wiki.archlinux.org/index.php/Installation_guide#Boot_loader)
- [4重新启动](https://wiki.archlinux.org/index.php/Installation_guide#Reboot)
- [5安装后](https://wiki.archlinux.org/index.php/Installation_guide#Post-installation)

## 预安装

可以从“ [下载”](https://archlinux.org/download/)页面获取安装媒体及其[GnuPG](https://wiki.archlinux.org/index.php/GnuPG)签名。

### 验证签名

建议在使用前验证图像签名，尤其是从*HTTP镜像*下载时，通常容易拦截下载以[提供恶意图像](https://www2.cs.arizona.edu/stork/packagemanagersecurity/attacks-on-package-managers.html)。

在安装了[GnuPG](https://wiki.archlinux.org/index.php/GnuPG)的系统上，通过将*PGP签名*（在*Checksums*下）下载到ISO目录中，并使用以下命令进行[验证](https://wiki.archlinux.org/index.php/GnuPG#Verify_a_signature)来执行此操作：

```
$ gpg --keyserver-options auto-key-retrieve --verify archlinux- 版本 -x86_64.iso.sig
```

或者，从现有的Arch Linux安装运行：

```
$ pacman-key -v archlinux- 版本 -x86_64.iso.sig
```

**注意：**

- 如果签名是从镜像站点而不是从上述的[archlinux.org](https://archlinux.org/download/)下载的，则可以对其进行操作。在这种情况下，请确保用于解码签名的公钥已由另一个可信任的密钥签名。该`gpg`命令将输出公共密钥的指纹。
- 验证签名真实性的另一种方法是，确保公钥的指纹与签署ISO文件的[Arch Linux开发人员](https://www.archlinux.org/people/developers/)的密钥指纹相同。有关验证密钥的公共密钥过程的更多信息，请参见[Wikipedia：公共密钥加密](https://en.wikipedia.org/wiki/Public-key_cryptography)。

### 启动实时环境

可以从[USB闪存驱动器](https://wiki.archlinux.org/index.php/USB_flash_installation_media)，[光盘](https://wiki.archlinux.org/index.php/Optical_disc_drive#Burning)或具有[PXE](https://wiki.archlinux.org/index.php/PXE)的网络引导实时环境。有关替代的安装方式，请参阅[Category：安装过程](https://wiki.archlinux.org/index.php/Category:Installation_process)。

- 如启动屏幕上所示，通常通过在[POST](https://en.wikipedia.org/wiki/Power-on_self_test)阶段按一个键来将当前引导设备指向包含Arch安装介质的驱动器。有关详细信息，请参阅主板的手册。
- 当出现“ Arch”菜单时，选择“ *Boot Arch Linux”*，然后按`Enter`进入安装环境。
- 见[README.bootparams](https://projects.archlinux.org/archiso.git/tree/docs/README.bootparams)的列表[启动参数](https://wiki.archlinux.org/index.php/Kernel_parameters#Configuration)，并[packages.x86_64](https://git.archlinux.org/archiso.git/tree/configs/releng/packages.x86_64)为包括包的列表。
- 您将以root用户身份在第一个[虚拟控制台](https://en.wikipedia.org/wiki/Virtual_console)上登录，并显示[Zsh](https://wiki.archlinux.org/index.php/Zsh) Shell提示符。

要切换到其他控制台（例如，通过安装旁边的[ELink](https://wiki.archlinux.org/index.php/ELinks)查看本指南），请使用[快捷方式](https://wiki.archlinux.org/index.php/Keyboard_shortcuts)。要[编辑](https://wiki.archlinux.org/index.php/Textedit)配置文件，可以使用[nano](https://wiki.archlinux.org/index.php/Nano#Usage)，[vi](https://en.wikipedia.org/wiki/vi)和[vim](https://wiki.archlinux.org/index.php/Vim#Usage)。 `Alt+*arrow*`

### 设置键盘布局

默认的[控制台键盘映射](https://wiki.archlinux.org/index.php/Console_keymap)是[US](https://en.wikipedia.org/wiki/File:KB_United_States-NoAltGr.svg)。可用的布局可以列出：

```
＃ls /usr/share/kbd/keymaps/**/*.map.gz
```

要修改布局，请将相应的文件名附加到[loadkeys（1）](https://jlk.fjfi.cvut.cz/arch/manpages/man/loadkeys.1)，省略路径和文件扩展名。例如，要设置[德语](https://en.wikipedia.org/wiki/File:KB_Germany.svg)键盘布局：

```
＃loadkeys de-latin1
```

[控制台字体](https://wiki.archlinux.org/index.php/Console_fonts)位于`/usr/share/kbd/consolefonts/`并且可以使用[setfont（8）](https://jlk.fjfi.cvut.cz/arch/manpages/man/setfont.8)进行设置。

### 验证启动模式

如果在[UEFI](https://wiki.archlinux.org/index.php/UEFI)主板上启用了UEFI模式，则[Archiso](https://wiki.archlinux.org/index.php/Archiso)将通过[systemd-boot](https://wiki.archlinux.org/index.php/Systemd-boot)相应地[引导](https://wiki.archlinux.org/index.php/Boot) Arch Linux 。要验证这一点，请列出[efivars](https://wiki.archlinux.org/index.php/UEFI#UEFI_variables)目录：

```
＃ls / sys / firmware / efi / efivars
```

如果该目录不存在，则系统可以[BIOS](https://en.wikipedia.org/wiki/BIOS)或CSM模式启动。有关详细信息，请参阅主板的手册。

### 连接到互联网

要设置网络连接，请执行以下步骤：

- 确保已列出并启用您的

  网络接口

  ，例如使用

  [ip-link（8）](https://jlk.fjfi.cvut.cz/arch/manpages/man/ip-link.8)

  ：

  ```
  ＃ip链接
  ```

- 连接到网络。插入以太网电缆或[连接到无线局域网](https://wiki.archlinux.org/index.php/Wireless_network_configuration)。

- 配置您的网络连接：

  - [静态IP地址](https://wiki.archlinux.org/index.php/Network_configuration#Static_IP_address)
  - 动态IP地址：使用[DHCP](https://wiki.archlinux.org/index.php/DHCP)。

- 可以使用

  ping

  验证连接：

  ```
  ＃ping archlinux.org
  ```

### 更新系统时钟

使用[timedatectl（1）](https://jlk.fjfi.cvut.cz/arch/manpages/man/timedatectl.1)确保系统时钟准确：

```
＃timedatectl set-ntp true
```

要检查服务状态，请使用`timedatectl status`。

### 分区磁盘

当实时系统识别出磁盘后，会将磁盘分配给诸如或的[块设备](https://wiki.archlinux.org/index.php/Block_device)。要标识这些设备，请使用[lsblk](https://wiki.archlinux.org/index.php/Lsblk)或*fdisk*。 `/dev/sda``/dev/nvme0n1`

```
＃fdisk -l
```

结果以或结尾`rom`，`loop`或者`airoot`可以忽略。

下面[分区](https://wiki.archlinux.org/index.php/Partition)都**需要**对所选择的设备：

- 根目录的一个分区`/`。
- 如果启用了[UEFI，](https://wiki.archlinux.org/index.php/UEFI)则为[EFI系统分区](https://wiki.archlinux.org/index.php/EFI_system_partition)。

如果要为[LVM](https://wiki.archlinux.org/index.php/LVM)，[系统加密](https://wiki.archlinux.org/index.php/Dm-crypt)或[RAID](https://wiki.archlinux.org/index.php/RAID)创建任何堆叠式块设备，请立即执行。

#### 示例布局

| 带[MBR的](https://wiki.archlinux.org/index.php/MBR) BIOS |               |                                                              |                |
| :------------------------------------------------------: | :-----------: | :----------------------------------------------------------: | :------------: |
|                          挂载点                          |     划分      |   [分区类型](https://en.wikipedia.org/wiki/Partition_type)   |    建议尺寸    |
|                          `/mnt`                          | `/dev/sd*X*1` |                           的Linux                            | 设备的其余部分 |
|                          [交换]                          | `/dev/sd*X*2` |                          Linux交换                           |  超过512 MiB   |
|  UEFI与[GPT](https://wiki.archlinux.org/index.php/GPT)   |               |                                                              |                |
|                          挂载点                          |     划分      | [分区类型](https://en.wikipedia.org/wiki/GUID_Partition_Table#Partition_type_GUIDs) |    建议尺寸    |
|               `/mnt/boot` 要么 `/mnt/efi`                | `/dev/sd*X*1` | [EFI系统分区](https://wiki.archlinux.org/index.php/EFI_system_partition) |  260–512 MiB   |
|                          `/mnt`                          | `/dev/sd*X*2` |                     Linux x86-64根（/）                      | 设备的其余部分 |
|                          [交换]                          | `/dev/sd*X*3` |                          Linux交换                           |  超过512 MiB   |

另请参见[Partitioning＃Example布局](https://wiki.archlinux.org/index.php/Partitioning#Example_layouts)。

**注意：**

- 例如，使用[fdisk](https://wiki.archlinux.org/index.php/Fdisk)或[parted](https://wiki.archlinux.org/index.php/Parted)修改分区表。`fdisk /dev/sd*X*`
- 可以在[交换文件上](https://wiki.archlinux.org/index.php/Swap_file)为支持该文件系统的文件系统设置[交换](https://wiki.archlinux.org/index.php/Swap)空间。

### 格式化分区

创建分区后，必须使用适当的[文件系统对](https://wiki.archlinux.org/index.php/File_system)每个分区进行格式化。例如，如果根分区已打开并且将包含文件系统，请运行： `/dev/sd*X*1``*ext4*`

```
＃mkfs。ext4 / dev / sd X1
```

如果您创建了交换分区，请使用*mkswap*对其进行*初始化*：

```
＃mkswap / dev / sd X2 
＃swapon / dev / sd X2
```

有关详细信息，请参见[文件系统＃创建文件系统](https://wiki.archlinux.org/index.php/File_systems#Create_a_file_system)。

### 挂载文件系统

将根分区上的文件系统[挂载](https://wiki.archlinux.org/index.php/Mount)到`/mnt`，例如：

```
＃挂载/ dev / sd X1 / mnt
```

创建所有剩余的挂载点（例如`/mnt/efi`）并挂载其相应的分区。

[genfstab](https://git.archlinux.org/arch-install-scripts.git/tree/genfstab.in)稍后将检测已安装的文件系统和交换空间。

## 安装

### 选择镜子

必须从中定义的[镜像服务器](https://wiki.archlinux.org/index.php/Mirrors)下载要安装的软件包`/etc/pacman.d/mirrorlist`。在实时系统上，将启用所有镜像，并按创建镜像时的同步状态和速度对其进行排序。

镜像在列表中的位置越高，下载软件包时它的优先级越高。您可能需要相应地编辑文件，并将地理位置最近的镜像移到列表的顶部，尽管应考虑其他条件。

稍后该文件将由*pacstrap*复制到新系统，因此值得正确使用。

### 安装基本软件包

使用[pacstrap](https://projects.archlinux.org/arch-install-scripts.git/tree/pacstrap.in)脚本安装通用硬件的[基本](https://www.archlinux.org/packages/?name=base)软件包，Linux [内核](https://wiki.archlinux.org/index.php/Kernel)和固件：

```
＃pacstrap / mnt基本linux linux-firmware
```

**提示：**您可以用[linux](https://www.archlinux.org/packages/?name=linux)替代您选择的[内核](https://wiki.archlinux.org/index.php/Kernel)软件包。如果您知道自己在做什么，则可以省略内核或固件软件包的安装。

该[基地](https://www.archlinux.org/packages/?name=base)包不包括从实况安装所有的工具，所以在安装其它软件包可以为一个全功能的基本系统是必要的。特别要考虑安装：

- 用户空间实用程序，用于管理将在系统上使用的[文件系统](https://wiki.archlinux.org/index.php/File_systems)，
- 用于访问[RAID](https://wiki.archlinux.org/index.php/RAID)或[LVM](https://wiki.archlinux.org/index.php/LVM)分区的实用程序，
- [linux-firmware中](https://www.archlinux.org/packages/?name=linux-firmware)未包含的其他设备的特定[固件](https://www.archlinux.org/packages/?name=linux-firmware)，
- [网络](https://wiki.archlinux.org/index.php/Networking)所需的软件，
- 一个[文本编辑器](https://wiki.archlinux.org/index.php/Text_editor)，
- 用于访问[手册](https://wiki.archlinux.org/index.php/Man)页和[信息](https://wiki.archlinux.org/index.php/Info)页中的文档的软件包：[man-db](https://www.archlinux.org/packages/?name=man-db)，[man-pages](https://www.archlinux.org/packages/?name=man-pages)和[texinfo](https://www.archlinux.org/packages/?name=texinfo)。

要[安装](https://wiki.archlinux.org/index.php/Install)其他软件包或软件包组，请将名称附加到上面的*pacstrap*命令（以空格分隔）或在[chroot到新系统中时](https://wiki.archlinux.org/index.php/Installation_guide#Chroot)使用[pacman](https://wiki.archlinux.org/index.php/Pacman)。为了进行比较，可以在packages.x86_64中找到实时系统中可用的[软件包](https://projects.archlinux.org/archiso.git/tree/configs/releng/packages.x86_64)。

## 配置系统

### Fstab

生成一个[fstab](https://wiki.archlinux.org/index.php/Fstab)文件（分别使用`-U`或`-L`定义[UUID](https://wiki.archlinux.org/index.php/UUID)或标签）：

```
＃genfstab -U / mnt >> / mnt / etc / fstab
```

检查生成的`/mnt/etc/fstab`文件，并在出现错误的情况下对其进行编辑。

### Chroot

[将root更改](https://wiki.archlinux.org/index.php/Change_root)为新系统：

```
＃arch-chroot / mnt
```

### 时区

设置[时区](https://wiki.archlinux.org/index.php/Time_zone)：

```
ln -sf /usr/share/zoneinfo/Asia/Shanghai /etc/localtime

```

运行[hwclock（8）](https://jlk.fjfi.cvut.cz/arch/manpages/man/hwclock.8)生成`/etc/adjtime`：

```
＃hwclock --systohc
```

该命令假定硬件时钟设置为[UTC](https://en.wikipedia.org/wiki/UTC)。有关详细信息，请参见[系统时间＃时间标准](https://wiki.archlinux.org/index.php/System_time#Time_standard)。

### 本土化

取消注释`en_US.UTF-8 UTF-8`和其他必要[的语言环境](https://wiki.archlinux.org/index.php/Locale)中`/etc/locale.gen`，并与他们产生：

```
＃locale-gen
```

创建[locale.conf（5）](https://jlk.fjfi.cvut.cz/arch/manpages/man/locale.conf.5)文件，并相应地设置`LANG` [变量](https://wiki.archlinux.org/index.php/Variable)：

```
/etc/locale.conf
LANG = en_US.UTF-8
```

如果[设置键盘布局](https://wiki.archlinux.org/index.php/Installation_guide#Set_the_keyboard_layout)，请在[vconsole.conf（5）](https://jlk.fjfi.cvut.cz/arch/manpages/man/vconsole.conf.5)中[保留](https://jlk.fjfi.cvut.cz/arch/manpages/man/vconsole.conf.5)更改：

```
/etc/vconsole.conf
KEYMAP = de-latin1
```

### 网络配置

创建[主机名](https://wiki.archlinux.org/index.php/Hostname)文件：

```
/ etc /主机名
myhostname
```

将匹配的条目添加到[主机（5）](https://jlk.fjfi.cvut.cz/arch/manpages/man/hosts.5)：

```
/ etc / hosts
127.0.0.1本地主机
:: 1本地主机
127.0.1.1	 myhostname .localdomain	 myhostname
```

如果系统具有永久IP地址，则应使用而不是`127.0.1.1`。

完成新安装环境的[网络配置](https://wiki.archlinux.org/index.php/Network_configuration)，包括安装首选的[网络管理](https://wiki.archlinux.org/index.php/Network_management)软件。

### 初始化文件

通常不需要创建新的*initramfs*，因为[mkinitcpio](https://wiki.archlinux.org/index.php/Mkinitcpio)是在使用*pacstrap*安装[内核](https://wiki.archlinux.org/index.php/Kernel)软件包时*运行的*。

对于[LVM](https://wiki.archlinux.org/index.php/Install_Arch_Linux_on_LVM#Adding_mkinitcpio_hooks)，[系统加密](https://wiki.archlinux.org/index.php/Dm-crypt)或[RAID](https://wiki.archlinux.org/index.php/RAID#Configure_mkinitcpio)，修改[mkinitcpio.conf（5）](https://jlk.fjfi.cvut.cz/arch/manpages/man/mkinitcpio.conf.5)并重新创建initramfs映像：

```
＃mkinitcpio -P
```

### 根密码

设置root [密码](https://wiki.archlinux.org/index.php/Password)：

```
＃passwd
```

### 引导加载程序

```
pacman -S grub efibootmgr fish zsh networkmanager intel-ucode os-prober neovim vi wpa_supplicant ttf-dejavu wqy-microhei

mkdir /boot/grub
grub-mkconfig > /boot/grub/grub.cfg

查看架构
uname -m
安装grub
grub-install --target=x86_64-efi --efi-directory=/boot

```



选择并安装支持Linux的[引导加载程序](https://wiki.archlinux.org/index.php/Boot_loader)。如果您具有Intel或AMD CPU，请另外启用[微代码](https://wiki.archlinux.org/index.php/Microcode)更新。

## 重启

通过键入`exit`或按退出chroot环境`Ctrl+d`。

（可选）使用以下命令手动卸载所有分区`umount -R /mnt`：这样可以注意到任何“繁忙”的分区，并使用[fuser（1）](https://jlk.fjfi.cvut.cz/arch/manpages/man/fuser.1)查找原因。

最后，通过键入以下内容来重新启动计算机`reboot`：任何仍在挂载的分区将由*systemd*自动卸载。请记住要删除安装介质，然后使用root帐户登录到新系统。

## 安装后

请参阅有关系统管理指南和安装后教程的[一般建议](https://wiki.archlinux.org/index.php/General_recommendations)（如设置图形用户界面，声音或触摸板）。

有关可能感兴趣[的应用程序列表](https://wiki.archlinux.org/index.php/List_of_applications)，请参阅[应用程序列表](https://wiki.archlinux.org/index.php/List_of_applications)。





# 原文

# Installation guide

[Jump to navigation](https://wiki.archlinux.org/index.php/Installation_guide#mw-head)[Jump to search](https://wiki.archlinux.org/index.php/Installation_guide#p-search)

This document is a guide for installing [Arch Linux](https://wiki.archlinux.org/index.php/Arch_Linux) from the live system booted with the official installation image. Before installing, it would be advised to view the [FAQ](https://wiki.archlinux.org/index.php/FAQ). For conventions used in this document, see [Help:Reading](https://wiki.archlinux.org/index.php/Help:Reading). In particular, code examples may contain placeholders (formatted in `*italics*`) that must be replaced manually.

For more detailed instructions, see the respective [ArchWiki](https://wiki.archlinux.org/index.php/ArchWiki) articles or the various programs' [man pages](https://wiki.archlinux.org/index.php/Man_page), both linked from this guide. For interactive help, the [IRC channel](https://wiki.archlinux.org/index.php/IRC_channel) and the [forums](https://bbs.archlinux.org/) are also available.

Arch Linux should run on any [x86_64](https://en.wikipedia.org/wiki/X86-64)-compatible machine with a minimum of 512 MiB RAM. A basic installation should take less than 800 MiB of disk space. As the installation process needs to retrieve packages from a remote repository, this guide assumes a working internet connection is available.

## Contents



- 1Pre-installation
  - [1.1Verify signature](https://wiki.archlinux.org/index.php/Installation_guide#Verify_signature)
  - [1.2Boot the live environment](https://wiki.archlinux.org/index.php/Installation_guide#Boot_the_live_environment)
  - [1.3Set the keyboard layout](https://wiki.archlinux.org/index.php/Installation_guide#Set_the_keyboard_layout)
  - [1.4Verify the boot mode](https://wiki.archlinux.org/index.php/Installation_guide#Verify_the_boot_mode)
  - [1.5Connect to the internet](https://wiki.archlinux.org/index.php/Installation_guide#Connect_to_the_internet)
  - [1.6Update the system clock](https://wiki.archlinux.org/index.php/Installation_guide#Update_the_system_clock)
  - 1.7Partition the disks
    - [1.7.1Example layouts](https://wiki.archlinux.org/index.php/Installation_guide#Example_layouts)
  - [1.8Format the partitions](https://wiki.archlinux.org/index.php/Installation_guide#Format_the_partitions)
  - [1.9Mount the file systems](https://wiki.archlinux.org/index.php/Installation_guide#Mount_the_file_systems)
- 2Installation
  - [2.1Select the mirrors](https://wiki.archlinux.org/index.php/Installation_guide#Select_the_mirrors)
  - [2.2Install essential packages](https://wiki.archlinux.org/index.php/Installation_guide#Install_essential_packages)
- 3Configure the system
  - [3.1Fstab](https://wiki.archlinux.org/index.php/Installation_guide#Fstab)
  - [3.2Chroot](https://wiki.archlinux.org/index.php/Installation_guide#Chroot)
  - [3.3Time zone](https://wiki.archlinux.org/index.php/Installation_guide#Time_zone)
  - [3.4Localization](https://wiki.archlinux.org/index.php/Installation_guide#Localization)
  - [3.5Network configuration](https://wiki.archlinux.org/index.php/Installation_guide#Network_configuration)
  - [3.6Initramfs](https://wiki.archlinux.org/index.php/Installation_guide#Initramfs)
  - [3.7Root password](https://wiki.archlinux.org/index.php/Installation_guide#Root_password)
  - [3.8Boot loader](https://wiki.archlinux.org/index.php/Installation_guide#Boot_loader)
- [4Reboot](https://wiki.archlinux.org/index.php/Installation_guide#Reboot)
- [5Post-installation](https://wiki.archlinux.org/index.php/Installation_guide#Post-installation)

## Pre-installation

The installation media and their [GnuPG](https://wiki.archlinux.org/index.php/GnuPG) signatures can be acquired from the [Download](https://archlinux.org/download/) page.

### Verify signature

It is recommended to verify the image signature before use, especially when downloading from an *HTTP mirror*, where downloads are generally prone to be intercepted to [serve malicious images](https://www2.cs.arizona.edu/stork/packagemanagersecurity/attacks-on-package-managers.html).

On a system with [GnuPG](https://wiki.archlinux.org/index.php/GnuPG) installed, do this by downloading the *PGP signature* (under *Checksums*) to the ISO directory, and [verifying](https://wiki.archlinux.org/index.php/GnuPG#Verify_a_signature) it with:

```
$ gpg --keyserver-options auto-key-retrieve --verify archlinux-version-x86_64.iso.sig
```

Alternatively, from an existing Arch Linux installation run:

```
$ pacman-key -v archlinux-version-x86_64.iso.sig
```

**Note:**

- The signature itself could be manipulated if it is downloaded from a mirror site, instead of from [archlinux.org](https://archlinux.org/download/) as above. In this case, ensure that the public key, which is used to decode the signature, is signed by another, trustworthy key. The `gpg` command will output the fingerprint of the public key.
- Another method to verify the authenticity of the signature is to ensure that the public key's fingerprint is identical to the key fingerprint of the [Arch Linux developer](https://www.archlinux.org/people/developers/) who signed the ISO-file. See [Wikipedia:Public-key cryptography](https://en.wikipedia.org/wiki/Public-key_cryptography) for more information on the public-key process to authenticate keys.

### Boot the live environment

The live environment can be booted from a [USB flash drive](https://wiki.archlinux.org/index.php/USB_flash_installation_media), an [optical disc](https://wiki.archlinux.org/index.php/Optical_disc_drive#Burning) or a network with [PXE](https://wiki.archlinux.org/index.php/PXE). For alternative means of installation, see [Category:Installation process](https://wiki.archlinux.org/index.php/Category:Installation_process).

- Pointing the current boot device to a drive containing the Arch installation media is typically achieved by pressing a key during the [POST](https://en.wikipedia.org/wiki/Power-on_self_test) phase, as indicated on the splash screen. Refer to your motherboard's manual for details.
- When the Arch menu appears, select *Boot Arch Linux* and press `Enter` to enter the installation environment.
- See [README.bootparams](https://projects.archlinux.org/archiso.git/tree/docs/README.bootparams) for a list of [boot parameters](https://wiki.archlinux.org/index.php/Kernel_parameters#Configuration), and [packages.x86_64](https://git.archlinux.org/archiso.git/tree/configs/releng/packages.x86_64) for a list of included packages.
- You will be logged in on the first [virtual console](https://en.wikipedia.org/wiki/Virtual_console) as the root user, and presented with a [Zsh](https://wiki.archlinux.org/index.php/Zsh) shell prompt.

To switch to a different console—for example, to view this guide with [ELinks](https://wiki.archlinux.org/index.php/ELinks) alongside the installation—use the `Alt+*arrow*` [shortcut](https://wiki.archlinux.org/index.php/Keyboard_shortcuts). To [edit](https://wiki.archlinux.org/index.php/Textedit) configuration files, [nano](https://wiki.archlinux.org/index.php/Nano#Usage), [vi](https://en.wikipedia.org/wiki/vi) and [vim](https://wiki.archlinux.org/index.php/Vim#Usage) are available.

### Set the keyboard layout

The default [console keymap](https://wiki.archlinux.org/index.php/Console_keymap) is [US](https://en.wikipedia.org/wiki/File:KB_United_States-NoAltGr.svg). Available layouts can be listed with:

```
# ls /usr/share/kbd/keymaps/**/*.map.gz
```

To modify the layout, append a corresponding file name to [loadkeys(1)](https://jlk.fjfi.cvut.cz/arch/manpages/man/loadkeys.1), omitting path and file extension. For example, to set a [German](https://en.wikipedia.org/wiki/File:KB_Germany.svg) keyboard layout:

```
# loadkeys de-latin1
```

[Console fonts](https://wiki.archlinux.org/index.php/Console_fonts) are located in `/usr/share/kbd/consolefonts/` and can likewise be set with [setfont(8)](https://jlk.fjfi.cvut.cz/arch/manpages/man/setfont.8).

### Verify the boot mode

If UEFI mode is enabled on an [UEFI](https://wiki.archlinux.org/index.php/UEFI) motherboard, [Archiso](https://wiki.archlinux.org/index.php/Archiso) will [boot](https://wiki.archlinux.org/index.php/Boot) Arch Linux accordingly via [systemd-boot](https://wiki.archlinux.org/index.php/Systemd-boot). To verify this, list the [efivars](https://wiki.archlinux.org/index.php/UEFI#UEFI_variables) directory:

```
# ls /sys/firmware/efi/efivars
```

If the directory does not exist, the system may be booted in [BIOS](https://en.wikipedia.org/wiki/BIOS) or CSM mode. Refer to your motherboard's manual for details.

### Connect to the internet

To set up a network connection, go through the following steps:

- Ensure your

   

  network interface

   

  is listed and enabled, for example with

   

  [ip-link(8)](https://jlk.fjfi.cvut.cz/arch/manpages/man/ip-link.8)

  :

  ```
  # ip link
  ```

- Connect to the network. Plug in the Ethernet cable or [connect to the wireless LAN](https://wiki.archlinux.org/index.php/Wireless_network_configuration).

- Configure your network connection:

  - [Static IP address](https://wiki.archlinux.org/index.php/Network_configuration#Static_IP_address)
  - Dynamic IP address: use [DHCP](https://wiki.archlinux.org/index.php/DHCP).

- The connection may be verified with

   

  ping

  :

  ```
  # ping archlinux.org
  ```

### Update the system clock

Use [timedatectl(1)](https://jlk.fjfi.cvut.cz/arch/manpages/man/timedatectl.1) to ensure the system clock is accurate:

```
# timedatectl set-ntp true
```

To check the service status, use `timedatectl status`.

### Partition the disks

When recognized by the live system, disks are assigned to a [block device](https://wiki.archlinux.org/index.php/Block_device) such as `/dev/sda` or `/dev/nvme0n1`. To identify these devices, use [lsblk](https://wiki.archlinux.org/index.php/Lsblk) or *fdisk*.

```
# fdisk -l
```

Results ending in `rom`, `loop` or `airoot` may be ignored.

The following [partitions](https://wiki.archlinux.org/index.php/Partition) are **required** for a chosen device:

- One partition for the root directory `/`.
- If [UEFI](https://wiki.archlinux.org/index.php/UEFI) is enabled, an [EFI system partition](https://wiki.archlinux.org/index.php/EFI_system_partition).

If you want to create any stacked block devices for [LVM](https://wiki.archlinux.org/index.php/LVM), [system encryption](https://wiki.archlinux.org/index.php/Dm-crypt) or [RAID](https://wiki.archlinux.org/index.php/RAID), do it now.

#### Example layouts

| BIOS with [MBR](https://wiki.archlinux.org/index.php/MBR) |               |                                                              |                         |
| :-------------------------------------------------------: | :-----------: | :----------------------------------------------------------: | :---------------------: |
|                        Mount point                        |   Partition   | [Partition type](https://en.wikipedia.org/wiki/Partition_type) |     Suggested size      |
|                          `/mnt`                           | `/dev/sd*X*1` |                            Linux                             | Remainder of the device |
|                          [SWAP]                           | `/dev/sd*X*2` |                          Linux swap                          |    More than 512 MiB    |
| UEFI with [GPT](https://wiki.archlinux.org/index.php/GPT) |               |                                                              |                         |
|                        Mount point                        |   Partition   | [Partition type](https://en.wikipedia.org/wiki/GUID_Partition_Table#Partition_type_GUIDs) |     Suggested size      |
|                 `/mnt/boot` or `/mnt/efi`                 | `/dev/sd*X*1` | [EFI system partition](https://wiki.archlinux.org/index.php/EFI_system_partition) |       260–512 MiB       |
|                          `/mnt`                           | `/dev/sd*X*2` |                    Linux x86-64 root (/)                     | Remainder of the device |
|                          [SWAP]                           | `/dev/sd*X*3` |                          Linux swap                          |    More than 512 MiB    |

See also [Partitioning#Example layouts](https://wiki.archlinux.org/index.php/Partitioning#Example_layouts).

**Note:**

- Use [fdisk](https://wiki.archlinux.org/index.php/Fdisk) or [parted](https://wiki.archlinux.org/index.php/Parted) to modify partition tables, for example `fdisk /dev/sd*X*`.
- [Swap](https://wiki.archlinux.org/index.php/Swap) space can be set on a [swap file](https://wiki.archlinux.org/index.php/Swap_file) for file systems supporting it.

### Format the partitions

Once the partitions have been created, each must be formatted with an appropriate [file system](https://wiki.archlinux.org/index.php/File_system). For example, if the root partition is on `/dev/sd*X*1` and will contain the `*ext4*` file system, run:

```
# mkfs.ext4 /dev/sdX1
```

If you created a partition for swap, initialize it with *mkswap*:

```
# mkswap /dev/sdX2
# swapon /dev/sdX2
```

See [File systems#Create a file system](https://wiki.archlinux.org/index.php/File_systems#Create_a_file_system) for details.

### Mount the file systems

[Mount](https://wiki.archlinux.org/index.php/Mount) the file system on the root partition to `/mnt`, for example:

```
# mount /dev/sdX1 /mnt
```

Create any remaining mount points (such as `/mnt/efi`) and mount their corresponding partitions.

[genfstab](https://git.archlinux.org/arch-install-scripts.git/tree/genfstab.in) will later detect mounted file systems and swap space.

## Installation

### Select the mirrors

Packages to be installed must be downloaded from [mirror servers](https://wiki.archlinux.org/index.php/Mirrors), which are defined in `/etc/pacman.d/mirrorlist`. On the live system, all mirrors are enabled, and sorted by their synchronization status and speed at the time the installation image was created.

The higher a mirror is placed in the list, the more priority it is given when downloading a package. You may want to edit the file accordingly, and move the geographically closest mirrors to the top of the list, although other criteria should be taken into account.

This file will later be copied to the new system by *pacstrap*, so it is worth getting right.

### Install essential packages

Use the [pacstrap](https://projects.archlinux.org/arch-install-scripts.git/tree/pacstrap.in) script to install the [base](https://www.archlinux.org/packages/?name=base) package, Linux [kernel](https://wiki.archlinux.org/index.php/Kernel) and firmware for common hardware:

```
# pacstrap /mnt base linux linux-firmware
```

**Tip:** You can substitute [linux](https://www.archlinux.org/packages/?name=linux) for a [kernel](https://wiki.archlinux.org/index.php/Kernel) package of your choice. You can omit the installation of the kernel or the firmware package if you know what you are doing.

The [base](https://www.archlinux.org/packages/?name=base) package does not include all tools from the live installation, so installing other packages may be necessary for a fully functional base system. In particular, consider installing:

- userspace utilities for the management of [file systems](https://wiki.archlinux.org/index.php/File_systems) that will be used on the system,
- utilities for accessing [RAID](https://wiki.archlinux.org/index.php/RAID) or [LVM](https://wiki.archlinux.org/index.php/LVM) partitions,
- specific firmware for other devices not included in [linux-firmware](https://www.archlinux.org/packages/?name=linux-firmware),
- software necessary for [networking](https://wiki.archlinux.org/index.php/Networking),
- a [text editor](https://wiki.archlinux.org/index.php/Text_editor),
- packages for accessing documentation in [man](https://wiki.archlinux.org/index.php/Man) and [info](https://wiki.archlinux.org/index.php/Info) pages: [man-db](https://www.archlinux.org/packages/?name=man-db), [man-pages](https://www.archlinux.org/packages/?name=man-pages) and [texinfo](https://www.archlinux.org/packages/?name=texinfo).

To [install](https://wiki.archlinux.org/index.php/Install) other packages or package groups, append the names to the *pacstrap* command above (space separated) or use [pacman](https://wiki.archlinux.org/index.php/Pacman) while [chrooted into the new system](https://wiki.archlinux.org/index.php/Installation_guide#Chroot). For comparison, packages available in the live system can be found in [packages.x86_64](https://projects.archlinux.org/archiso.git/tree/configs/releng/packages.x86_64).

## Configure the system

### Fstab

Generate an [fstab](https://wiki.archlinux.org/index.php/Fstab) file (use `-U` or `-L` to define by [UUID](https://wiki.archlinux.org/index.php/UUID) or labels, respectively):

```
# genfstab -U /mnt >> /mnt/etc/fstab
```

Check the resulting `/mnt/etc/fstab` file, and edit it in case of errors.

### Chroot

[Change root](https://wiki.archlinux.org/index.php/Change_root) into the new system:

```
# arch-chroot /mnt
```

### Time zone

Set the [time zone](https://wiki.archlinux.org/index.php/Time_zone):

```
# ln -sf /usr/share/zoneinfo/Region/City /etc/localtime
```

Run [hwclock(8)](https://jlk.fjfi.cvut.cz/arch/manpages/man/hwclock.8) to generate `/etc/adjtime`:

```
# hwclock --systohc
```

This command assumes the hardware clock is set to [UTC](https://en.wikipedia.org/wiki/UTC). See [System time#Time standard](https://wiki.archlinux.org/index.php/System_time#Time_standard) for details.

### Localization

Uncomment `en_US.UTF-8 UTF-8` and other needed [locales](https://wiki.archlinux.org/index.php/Locale) in `/etc/locale.gen`, and generate them with:

```
# locale-gen
```

Create the [locale.conf(5)](https://jlk.fjfi.cvut.cz/arch/manpages/man/locale.conf.5) file, and set the `LANG` [variable](https://wiki.archlinux.org/index.php/Variable) accordingly:

```
/etc/locale.conf
LANG=en_US.UTF-8
```

If you [set the keyboard layout](https://wiki.archlinux.org/index.php/Installation_guide#Set_the_keyboard_layout), make the changes persistent in [vconsole.conf(5)](https://jlk.fjfi.cvut.cz/arch/manpages/man/vconsole.conf.5):

```
/etc/vconsole.conf
KEYMAP=de-latin1
```

### Network configuration

Create the [hostname](https://wiki.archlinux.org/index.php/Hostname) file:

```
/etc/hostname
myhostname
```

Add matching entries to [hosts(5)](https://jlk.fjfi.cvut.cz/arch/manpages/man/hosts.5):

```
/etc/hosts
127.0.0.1	localhost
::1		localhost
127.0.1.1	myhostname.localdomain	myhostname
```

If the system has a permanent IP address, it should be used instead of `127.0.1.1`.

Complete the [network configuration](https://wiki.archlinux.org/index.php/Network_configuration) for the newly installed environment, that includes installing your preferred [network management](https://wiki.archlinux.org/index.php/Network_management) software.

### Initramfs

Creating a new *initramfs* is usually not required, because [mkinitcpio](https://wiki.archlinux.org/index.php/Mkinitcpio) was run on installation of the [kernel](https://wiki.archlinux.org/index.php/Kernel) package with *pacstrap*.

For [LVM](https://wiki.archlinux.org/index.php/Install_Arch_Linux_on_LVM#Adding_mkinitcpio_hooks), [system encryption](https://wiki.archlinux.org/index.php/Dm-crypt) or [RAID](https://wiki.archlinux.org/index.php/RAID#Configure_mkinitcpio), modify [mkinitcpio.conf(5)](https://jlk.fjfi.cvut.cz/arch/manpages/man/mkinitcpio.conf.5) and recreate the initramfs image:

```
# mkinitcpio -P
```

### Root password

Set the root [password](https://wiki.archlinux.org/index.php/Password):

```
# passwd
```

### Boot loader

Choose and install a Linux-capable [boot loader](https://wiki.archlinux.org/index.php/Boot_loader). If you have an Intel or AMD CPU, enable [microcode](https://wiki.archlinux.org/index.php/Microcode) updates in addition.

## Reboot

Exit the chroot environment by typing `exit` or pressing `Ctrl+d`.

Optionally manually unmount all the partitions with `umount -R /mnt`: this allows noticing any "busy" partitions, and finding the cause with [fuser(1)](https://jlk.fjfi.cvut.cz/arch/manpages/man/fuser.1).

Finally, restart the machine by typing `reboot`: any partitions still mounted will be automatically unmounted by *systemd*. Remember to remove the installation media and then login into the new system with the root account.

## Post-installation

See [General recommendations](https://wiki.archlinux.org/index.php/General_recommendations) for system management directions and post-installation tutorials (like setting up a graphical user interface, sound or a touchpad).

For a list of applications that may be of interest, see [List of applications](https://wiki.archlinux.org/index.php/List_of_applications).



















# [ArchLinux配置中文输入法]

配置输入法只需从安装输入法开始执行安装命令

\1. sudo pacman-mirrors -g

\2. sudo pacman-optimize && sync

\3. sudo pacman -Syyu

\4. 编辑 sudo nano /etc/pacman.conf 文件

[archlinuxcn]

SigLevel = Optional TrustedOnly

Server = https://mirrors.ustc.edu.cn/archlinuxcn/$arch

\5. sudo pacman -Syy && sudo pacman -S archlinuxcn-keyring

sudo pacman -S google-chrome 安装谷歌浏览器

安装输入法：

sudo pacman -S fcitx-im #默认全部安装

sudo pacman -S fcitx-configtool

sudo pacman -S fcitx-sogoupinyin

配置输入法：

编辑 sudo nano ~/.xprofile 文件

export LC_ALL=zh_CN.UTF-8

export GTK_IM_MODULE=fcitx

export QT_IM_MODULE=fcitx

export XMODIFIERS=“@im=fcitx”











# ArchLinux必备命令记录(manjaro)

添加新账户

useradd username新建账户;

useradd -d /home/xxx -m xxx创建用户，并同时生成用户目录，不然账户无法正常启用;

passwd username修改密码;

userdel -f username删除账户及其配置文件;

usermod -G gpname usrname修改用户所属组;

2、退出登录

logout

3、关机命令

shutdown now;立即关机;

shutdown 10:30;在10:30关机;

shutdown -r +5;5分钟后重启;

4、设置开机启动服务

systemctl enable servicename;设置为开机启动;

systemctl disable servicename;禁止开机启动;

5, ArchLinux的包管理系统: pacman

常用命令有：
        pacman -Sy abc                    和源同步后安装名为abc的包
        pacman -S abc                     从本地数据库中得到abc的信息，下载安装abc包
        pacman -Sf abc                    强制安装包abc
        pacman -Ss abc                   搜索有关abc信息的包
        pacman -Si abc                    从数据库中搜索包abc的信息
        pacman -Syu                        同步源，并更新系统
        pacman -Sy                          仅同步源
        pacman -R abc                     删除abc包
        pacman -Rc abc                   删除abc包和依赖abc的包
        pacman -Rsn abc                 移除包所有不需要的依赖包并删除其配置文件
        pacman -Sc                          清理/var/cache/pacman/pkg目录下的旧包
        pacman -Scc                        清除所有下载的包和数据库
        pacman -Sd abc                   忽略依赖性问题，安装包abc
        pacman -Su --ignore foo       升级时不升级包foo
        pacman -Sg abc                   查询abc这个包组包含的软件包
        pacman -Q                           列出系统中所有的包
        pacman -Q package             在本地包数据库搜索(查询)指定软件包
        pacman -Qi package            在本地包数据库搜索(查询)指定软件包并列出相关信息
        pacman -Q | wc -l                  统计当前系统中的包数量
        pacman -Qdt                         找出孤立包
        pacman -Rs $(pacman -Qtdq) 删除孤立软件包（递归的,小心用)
        pacman -U   abc.pkg.tar.gz      安装下载的abs包，或新编译的本地abc包
        pacman-optimize && sync        提高数据库访问速度

 

————————————————
版权声明：本文为CSDN博主「皮皮中的皮」的原创文章，遵循 CC 4.0 BY-SA 版权协议，转载请附上原文出处链接及本声明。
原文链接：https://blog.csdn.net/weixin_42408100/article/details/82526087













# **Arch安装过程  与必备软件**





最终效果


安装过程中如何连接wifi
方法1：
进入启动盘之后，敲wifi-menu，选择要连接wifi，保存配置，输入密码即可。

方法2：
查看无线网卡接口名称: ip link
连接网络： wpa_supplicant -B -i 网卡名称 -c <(wpa_passphrase wifi名称 wifi密码)
注意小于号后不能有空格

安装系统成功后，拔掉U盘，没有wifi，没有连接方法
俺没有装网卡连接的工具，又重新来了一遍。
重新用启用U盘加载， 挂载之前的分区
mount /dev/sda2 /mnt
mount /dev/sda1 /mnt/boot/efi

先连上wifi再说， 推荐使用wifi-menu
切换到已经安装好的系统： arch-chroot /mnt
安装dialog，这样下次开机就能使用wifi-menu了
pacman -S networkmanager dialog
pacman -S net-tools

然后进去之后wifi-menu连接，又炸了，看报错信息journalctl -xe说我已经连接

接着我就把网卡给关了 ip link set wlp2s0 down
然后按之前wifi配置文件重新连接就ok了！！！
netctl start /etc/netctl/wlp2s0-xxxx
ping一下，终于ok了！！！

下次重启后在连接，就用netctl start /etc/netctl/xxx-xxx就可以了！！！

配置DNS
如果不配置DNS的话，ping域名的时候，还有打开网站的时候，会有明显的卡顿感，ping ip则不会，这是DNS解析慢导致的。
编辑/etc/resolv.conf
添加一行 nameserver 114.114.114.114
上面的方法是临时修改的，下次重启还会变回来，要想永久修改，更改/etc/systemd/resolved.conf

安装sudo
安装sudo，配置文件在/etc/sudoers，对其进行配置
useradd -m -G wheel 用户名
passwd 用户名 改指定用户密码
passwd 改root用户密码
没权限保存的话，可用:wq!试试

安装openssh
pacman -S openssh
systemctl status sshd
systemctl start sshd
systemctl enable sshd

安装图形界面
安装xorg
sudo pacman -S xorg

安装xorg-xinit
sudo pacman -S xorg-xinit

配置
cp /etc/X11/xinit/xinitrc ~/.xinitrc
将后面几行，twm启动和xterm那里删除掉


删掉图片中内容

安装i3
sudo pacman -S i3
将启动桌面写入~/.xinitrc
~/.xinitrc结尾添加: exec i3
安装字体，否则可能无法正常显示: sudo pacman -S ttf-font-awesome wqy-bitmapfont wqy-microhei wqy-zenhei nerd-fonts-complete 我nerd-fonts-complete没找到

mod+w: 切换成折叠式窗口 mod+e: 取消折叠式/水平/竖直旋转

启动
startx 成功！！！

安装alacritty
sudo pacman -S alacritty
默认没有终端，可以测试，安装alacritty后，默认终端会变成alacritty
可设置终端字体大小，在配置文件的size，opacity是设置透明度，必须有compton支持
sudo pacman -S compton
将其写入i3配置中
exec_always --no-start-ip compton -b
更改alacritty的标题栏显示
在i3的配置中加入一行new_window pixel 1

安装dmenu
sudo pacman -S dmenu，然后$mod+d就有作用了

声音配置
cat /etc/group|grep audio 有一个组，看里面有没有用户。
usermod -aG audio 用户名 给用户添加到audio组.
安装alsa包
sudo pacman -S alsa-utils

然后可以用alsamixer 查看声卡配置
标有00的通道已经启用，标有MM的声道是静音的
按m键接触静音，使用↑增加音量，直到增益值为0

安装麦克风驱动：
sudo pacman -S pulseaudio

安装系统托盘图标
sudo pacman -S pasystray
我没装这个，好像没用

添加源
在/etc/pacman.conf最后面添加两行

[archlinuxcn]    
Server = https://mirrirs.tuna.tsinghua.edu.cn/archlinuxcn/$arch    
然后sudo pacman -Sy 同步源
然后安装sudo pacman -S archlinuxcn-keyring包导入GPG key

安装polybar
sudo pacman -S polybar
安装polybar的时候，下面会列出一些依赖包，有你已经安装的和未安装的，尽可能装上。
sudo pacman -S cmake 生成配置文件： install -Dm644 /usr/share/doc/polybar/config $HOME/.config/polybar/config
去查看配置文件： ~/.config/polybar/config
编写launch.sh，去看github上的wiki

#!/usr/bin/env bash

# Terminate already running bar instances
killall -q polybar

# Wait until the processes have been shut down
while pgrep -u $UID -x polybar >/dev/null; do sleep 1; done

# Launch bar1 and bar2
polybar bar1 &
polybar bar2 &

echo "Bars launched..."
继续按wifi，删掉i3bar，添加polybar
pass

安装字体： sudo pacman -S noto-fonts noto-fonts-cjk 
adobe-source-han-sans-cn-fonts

安装输入法
先安装fcitx框架：
sudo pacman -S fcitx fictx-im fcitx-configtools
安装rime输入法
sudo pacman -S fcitx-rime
之后重启i3，看看能否在i3bar或polybar中显示托盘图标

可以的话右键托盘图标Config Current Input Method中进行配置，添加rime输入法(台湾)

在i3的配置文件中添加启动fcitx exec_always --no-startup-id fcitx，和polybar配置完全一样

不需要往.xintrc中添加东西

然后我就能在chrome中输入中文，在alacritty中输入不了！！！
解决方法：
在/etc/environment中添加

export GTK_IM_MODULE=fcitx    
export QT_IM_MODULE=fcitx    
export XMODIFIERS=@im=fcitx    
默认将rime的繁体中文转换为简体中文：
vi ~/.config/fcitx/rime/build/luna_pinyin.schema.yaml
在switches配置段的name:simplication下增加一行：reset:1

修改按shift上屏: vi ~/.config/fcitx/rime/build/default.yml 修改配置段

ascii_composer/good_old_caps_lock: true
ascii_composer/switch_key:
  Caps_Lock: noop
  Shift_L: commit_code
  Shift_R: inline_ascii
  Control_L: clear
  Control_R: commit_text
一个大坑，把shift切换输入法关掉




rime进行输入方案的选择: ctrl+\

查看剪切版内容　ctrl+; 切换全角和半角: Shift+Space 中英文标点切换: ctrl+. 这个基本上不会用

安装chrome浏览器
pass

安装ranger
sudo pacman -S ranger
ranger显示隐藏文件: zh

安装图片浏览工具feh
sudo pacman -S feh

配置桌面背景图片
在i3的启动文件中进行配置
exec_always --no-startup-id feh --bg-scale 图片路径

配置多显示器
xrandr查看已经连接的显示器.
sudo pacman -S arandr 用图形界面配置显示器布局
完了可以导出成sh

解决鼠标总是处于忙碌状态
在i3的配置文件中，exec和exec_always后面都加上--no-startup-id

安装python和pip，python2对应的pip版本过高
sudo pacman -S python2 python-pip python2-pip
python2 -m pip install pip==9.0.3

配置shadowsocks客户端和proxycharins
sudo pip install shadowsocks    
sudo ln -s /usr/local/python/bin/sslocal /usr/bin/sslocal    
sudo vi /etc/shadowsocks.conf

{
"server":"your_server_ip",
"server_port":"your_server_port",
"local_address":"127.0.0.1",
"local_port":1080,
"password":"your_server_passwd",
"timeout":300,
"method":"aes-256-cfb"
}
sudo sslocal -c /etc/shadowsocks.conf -d start

接下来就能通过1080端口出去了

安装proxychains
sudo pacan -S proxychains
vi /etc/proxychains.conf
将最后一行改成 socks5 127.0.0.1:1080

接下来就可以使用proxychains了
proxychains wget https://www.google.com
让整个bash都走代理
proxychains bash

接下里配置插件SwitchyOmega
下载该插件和备份的配置文件，将配置文件导入到插件，选自动切换就ok了

安装qq
sudo pacman -S deepin.com.qq.im
如何报依赖包的问题，将/etc/pacman.conf中的multi源取消掉注释，在更新sudo pamcan -Syyu，在重装软件

配置先pass，要在i3中将其配置成浮动，在设置DPI，在安装依赖包...莫名其妙的好了

安装百度云
sudo pacman -S baidunetdisk-bin

安装els
https://github.com/AnthonyDiGirolamo/els

安装nvim
pass

HHKB键盘DIP开关配置
https://www.chenshaowen.com/blog/how-to-configure-the-hhkb-keyboard.html

关掉126，开启345，将i3的Win键改成了Alt HHKB按Fn+Q可进入蓝牙配对模式，也可按电源键三秒进入

安装epub阅读器
sudo pacman -S fbreader 启动: FBReader 使用说明: 和vim类似

j,k
f
<C-f>,<C-b>
c,l,i,o,g,Esc
可在右键设置里设置颜色，快捷键，字体等等。

安装pdf阅读器
sudo pacman -S foxitreader 这个很简单

安装office
sudo pacman -S wps-office

相关的主题：
相关教程：
22.3YUM线上升级机制|鸟哥的Linux私房菜：基础学习篇第四版【鸟哥的Linux私房菜：基础学习篇 第四版】
19.2核心与核心模块|鸟哥的Linux私房菜：基础学习篇第四版【鸟哥的Linux私房菜：基础学习篇 第四版】
22.4SRPM的使用：rpmbuild（Optional）|鸟哥的Linux私房菜：基础学习篇第四版【鸟哥的Linux私房菜：基础学习篇 第四版】
24.1编译前的任务：认识核心与取得核心源代码|鸟哥的Linux私房菜：基础学习篇第四版【鸟哥的Linux私房菜：基础学习篇 第四版】
Docker-ArchLinux安装教程|Docker教程中文版本【Docker教程中文版本】
16.5SELinux初探|鸟哥的Linux私房菜：基础学习篇第四版【鸟哥的Linux私房菜：基础学习篇 第四版】
17.3systemctl针对service类型的配置文件|鸟哥的Linux私房菜：基础学习篇第四版【鸟哥的Linux私房菜：基础学习篇 第四版】
17.4systemctl针对timer的配置文件|鸟哥的Linux私房菜：基础学习篇第四版【鸟哥的Linux私房菜：基础学习篇 第四版】