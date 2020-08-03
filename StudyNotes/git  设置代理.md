# git  设置代理

## 1	果代理类型是socks5进行如下设置即可

git config --global http.proxy socks5://129.28.151.185：8886

git config --global httpsproxy socks5://129.28.151.185：8886

## 2	果是普通的http/https进行如下设置即可

git config --global https.proxy http://127.0.0.1:1080

git config --global https.proxy https://127.0.0.1:1080

## 3	消代理设置

git config --global --unset http.proxy

git config --global --unset https.proxy