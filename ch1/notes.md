# Introduction

- Operating system as "software that manages computer's resources"
    - Software layer managing pc's resources for users/applications

- User interacts with application
    - Application executes in env provided by operating system
        - Operating system mediates access to underlying hardware

- For running multiple applications,
    - Operating system must be three roles:
        1. Referee
            - Manages resources shared between applications on same machine
        2. Illusionist
            - Illusion of infinite resources, despite limited resources
        3. Glue
            - Provide set of common services to promote sharing

    1. Referee
        - Resource allocation
        - Fault isolation
        - Communication between users/applications
    2. Illusionist
        - Virtualization
    3. Glue
---
# Operating System Evaluation

- Desirable criteria for operating systems:
    1. Reliability/availability
    2. Security
    3. Portability
    4. Performance
    5. Adoption

- Reliability: system does exactly what it is designed to do
- Availability: percentage of time system is usable
    - Variables:
        1. Mean time to failure: frequency of failures
        2. Mean time to repair: time to restore system to working state after failure

- Security: computer cannot be compromised by malicious attackers
    - Privacy: data on computer is accessibly only to authorized users
- To enforce security, an operating system requires:
    1. Enforcement mechanism: how operating system ensures only permitted actions allowed
    2. Security policy: defines who is allowed to access what data, and who can perform what operations

- Portability: provides applications with an abstraction of underlying computer hardware
    - Abstraction does not change as the hardware changes
        - Abstract Virtual Machine: provides applications a simple, standard way to interact with OS
            - AVM includes:
                - Application Programming Interface (API)
                    - List of function calls provided to applications by operating system
                - Memory access model
                - Which instructions can be legally executed
            - Well-designed AVM gives "fixed point" that both application/hardware can evolve independently
        - Hardware Abstrction Layer:  abstraction for OS regardless of hardware specifics

- Performance
    - Various metrics
        - Overhead: added resource cost of adding abstraction for applications
            - Efficiency: lack of overhead in abstraction
                - Measured via degree abstraction impedes performance
                    - eg. how much would performance improve if app could run on pure hardware, no OS?
        - Fairness: division of resources among different users/applications
            - Should resources be divided equally?
                - If not, how should OS decide which application task gets priority?
        - Response time/throughput
            - Response time (delay): how long it takes for a single task to run, start -> completion
            - Throughput: rate at which system completes tasks
        - Predicability: whether a system's response time (or other metric) is consistent over time

- Adoption
    - Network Effect: when value of a technology depends on not just its inherit qualities, but # of adopted users too
