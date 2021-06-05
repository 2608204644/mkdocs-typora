# Windows Terminal #

**安装 oh_my_posh**

Install-Module posh-git -Scope CurrentUser  

Install-Module oh-my-posh -Scope CurrentUser

if (!(Test-Path -Path $PROFILE )) { New-Item -Type File -Path $PROFILE -Force } 

notepad $PROFILE



Import-Module posh-git 
Import-Module oh-my-posh 
Set-PoshPrompt agnoster

导入到

```bash
C:\Users\Kuan\Documents\WindowsPowerShell\Microsoft.PowerShell_profile.ps1
```





字体在GitHub

https://ohmyposh.dev/docs/



**设置代理**

```
设置
set http_proxy=http://127.0.0.1:7890
set https_proxy=http://127.0.0.1:7890
取消
set http_proxy=
set https_proxy=
```