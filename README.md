R_TCP_SCANNER
=========

R_TCP_SCANNER is a small C project scanning TCP ports.

Port Scanning
-----------

A port scanner is a software application designed to probe a server or host for open ports. This is often used by administrators to verify security policies of their networks and by attackers to identify running services on a host with the view to compromise it.
A port scan or portscan can be defined as an attack that sends client requests to a range of server port addresses on a host, with the goal of finding an active port and exploiting a known vulnerability of that service, although the majority of uses of a port scan are not attacks and are simple probes to determine services available on a remote machine.
To portsweep is to scan multiple hosts for a specific listening port. The latter is typically used in searching for a specific service, for example, an SQL-based computer worm may portsweep looking for hosts listening on TCP port 1433

The simplest port scanners use the operating system's network functions and is generally the next option to go to when SYN is not a feasible option (described next). Nmap calls this mode connect scan, named after the Unix connect() system call. If a port is open, the operating system completes the TCP three-way handshake, and the port scanner immediately closes the connection to avoid performing a kind of Denial-of-service attack. Otherwise an error code is returned. This scan mode has the advantage that the user does not require special privileges. However, using the OS network functions prevents low-level control, so this scan type is less common. This method is "noisy", particularly if it is a "portsweep": the services can log the sender IP address and Intrusion detection systems can raise an alarm.

TCP/IP basic knowledge
--------------------

The design and operation of the Internet is based on the Internet Protocol Suite, commonly also called TCP/IP. In this system, hosts and host services are referenced using two components: an address and a port number. There are 65536 distinct and usable port numbers. Most services use a limited range of numbers.
Some port scanners scan only the most common port numbers, or ports most commonly associated with vulnerable services, on a given host. See: List of TCP and UDP port numbers.
The result of a scan on a port is usually generalized into one of three categories:
Open or Accepted: The host sent a reply indicating that a service is listening on the port.
Closed or Denied or Not Listening: The host sent a reply indicating that connections will be denied to the port.
Filtered, Dropped or Blocked: There was no reply from the host.
Open ports present two vulnerabilities of which administrators must be wary:
Security and stability concerns associated with the program responsible for delivering the service - Open ports.
Security and stability concerns associated with the operating system that is running on the host - Open or Closed ports.
Filtered ports do not tend to present vulnerabilities.


Project Usage and Output
-------------
```BASH
RocKK$ gcc main.c -o main
RocKK$ ./main 127.0.0.1 8860 8888
Port 8860 is open
Port 8861 is open
Port 8862 is open
Port 8863 is open
Port 8864 is open
Port 8865 is open
Port 8866 is closed
Port 8867 is open
Port 8868 is open
Port 8869 is open
Port 8870 is open
Port 8871 is open
Port 8872 is open
Port 8873 is open
Port 8874 is open
Port 8875 is open
Port 8876 is open
Port 8877 is open
Port 8878 is open
Port 8879 is open
Port 8880 is open
Port 8881 is open
Port 8882 is open
Port 8883 is open
Port 8884 is open
Port 8885 is open
Port 8886 is open
Port 8887 is open
Port 8888 is open
```


