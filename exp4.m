clc;clear all;close all;
m=10^5;
snr_dB=1:1:20;
for j=1:1:length(snr_dB)
    n_err=0;
    n_bits=0;
    while n_err<100
        inf_bits=round(rand(1,m));
        x=-2*(inf_bits-0.5);
        N0=1/10^(snr_dB(j)/10);
        n1=sqrt(N0/2).*abs((randn(1,length(x))+i*randn(1,length(x))));
        n2=sqrt(N0/2).*abs((randn(1,length(x))+i*randn(1,length(x))));
        h1=sqrt(1/2).*abs((randn(1,length(x))+i*randn(1,length(x))));
        h2=sqrt(1/2).*abs((randn(1,length(x))+i*randn(1,length(x))));
        y1=h1.*x+n1;
        y2=h2.*x+n2;
        y=(y1+y2)*05;
        exp_bits=y<0;
        diff=inf_bits-exp_bits;
        n_err=n_err+sum(abs(diff));
        n_bits=n_bits+length(inf_bits);
    end
    BER(j)=n_err/n_bits;
end
semilogy(snr_dB,BER,'-','LineWidth',2);
grid on;