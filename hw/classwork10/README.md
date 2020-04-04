# classwork week 10

*I pledge my honor that I have abided by the Stevens Honor System. - Joshua Schmidt* 4/3/2020

Please upload all the classwork material in one doc or pdf file.

Should contain: screenshots of running simulations, simulation statistics and comparisons with theoretical calculations for end-end delay for the M/M/1 simulation.

\newpage

## mm1

![mm1 network](./mm1_network.png){ width=100% }

\newpage

![omnetpp.ini file](./mm1_omnetpp_ini.png){ width=100% }

\newpage

![mm1 running](./mm1_running.png){ width=100% }

\newpage

![mm1 data](./mm1_data.png){ width=100% }

the average queuing time was 0.4768 seconds. The average queue length over time was 0.47627 units.

\newpage

## md1

![omnetpp.ini file](./md1_omnetpp_ini.png){ width=100% }

\newpage

![md1 running](./md1_running.png){ width=100% }

\newpage

![md1 data](./md1_data.png){ width=100% }

The average queuing time was 0.254419 seconds, with an average queue length of 0.25442 units.

Similar for M/D/1 - show omnetpp.ini modifications (screenshot), screenshot of simulation running, results from theoretical calculations and formula of dependence between M/M/1 and M/D/1 for average delay in queue and average number of customers in queue.

\newpage

## mm3

For M/M/3 - just the screenshots and statistics collected from the simulations.

- change service time to 0.5 seconds to get MD1, instead of exponential for MM1
- average inter-arrival time = end-to-end delay is lifetime
- queuing delay is average queue 

mu = 1/E[service time] 
lambda = 1 / E[inter-arr time] 
end-to-end-delay = 1/(mu-lambda) 

for mm3 we just need screenshots that it works

![mm3 network](./mm3_network.png){ width=100% }

\newpage

![omnetpp.ini file](./mm3_omnetpp_ini.png){ width=100% }

\newpage

![mm3 running](./mm3_running.png){ width=100% }

\newpage

![mm3 data](./mm3_data.png){ width=100% }
