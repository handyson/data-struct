# data-struct
> 数据结构测试

## 编译运行配置shell命令
```
function run-c() { 
    if [ ! -d "./bin" ]; then
        mkdir ./bin
    fi
    gcc $1.c -o ./bin/$1 && ./bin/$1
}
alias runc='run-c'
```

以上代码添加到`/etc/profile`

使用`runc {文件名}`运行代码