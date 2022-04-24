# Description

Console multithreaded client-server app for calculation sum of ASCII codes. The exchange of messages between clients and the server occurs over TCP/IP.

_Server example:_

```
----------------------------------
| Homework TCP Server ver. 1.0.1 |
----------------------------------

Enter port (0 = auto): 0

Server started on: "[Server IP]" : 1881


         "127.0.0.1" [ "24.05.2020" | "10:39:55" ]: "abc"

         "127.0.0.1" [ "24.05.2020" | "10:39:56" ]: "abc"
```

_Client example:_

```
----------------------------------
| Homework TCP Client ver. 1.0.2 |
----------------------------------

-> Enter server IP: localhost

-> Enter server port: 1881

-> Enter your message: abc

-> Enter send times: 2


        - Response by server:  "294"

        - Response by server:  "294"


[x] End of session.
```
