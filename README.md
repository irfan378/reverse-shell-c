### Change ip address and port in code 
```
	const char* ip="127.0.0.1";
	addr.sin_port=htons(4444);

```
```
gcc shell.c -o shell
./shell
```
