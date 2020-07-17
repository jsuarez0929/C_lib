### IP Calculator

---

#### Description:
IP Calculator provides the ability to determine if a given IP is a valid
private IP address and if so compares against other private IP addresses to
validate if overlapping occurs.

#### Procedure:
    1. Prompts user to provide as input an IP address and its subnet address
    2. Program calculates if given IP address is private ( according to RFC 1918
    https://tools.ietf.org/html/rfc1918 )
    3. Outputs IP Address info
        a. Given IP address
        b. Subnet
        c. Binary representation
        d. Is private
        e. CIDR notation
        f. Class
        g. Network ID
        h. Broadcast ID
        i. Number of hosts
    4. Second prompt will ask for a second IP or list of IPs and determine if
    above IP overlaps with those provided
        a. If so, output the overlapping IP address

##### TODO:
- Translate to python
- Connect to AWS api for retrieval of IP addresses
- Provide front-end capability
