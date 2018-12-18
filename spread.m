clc;close all;clear all;
m=10;
f_data=1;
f_chip=7;
fc=210;
fs=fc*3;
N=fs/f_chip;
snr_dB=1:1:16;
for jj=1:1:length(snr_dB)
    n_err=0;
    n_bits=0;
    while n_err<100
        inf_bits=round(rand(1,m));
        PN_seq=round(rand(11,1));
        j=1;
        for i=1:m
            for k=j:j+f_chip-1
                msg_spread(k)=inf_bits(i);
            end
        msg_spread(j:(j+f_chip-1))=xor(msg_spread(j:(j+f_chip-1))',PN_seq(1:f_chip));
        j=f_chip*i+1;
        end
        leng_msg_spread=length(msg_spread);
        
        x=-2*(msg_spread-0.5);
        N0=1/10^(snr_dB(jj)/10);
        y=x+sqrt(N0/2)*(randn(1,length(x))+i*(randn(1,length(x))));
        
        msg_demod=y<0;
        
        j=1;
        for i=1:m
            msg_demod(j:(j+f_chip-1))=xor(msg_demod(j:(j+f_chip-1))',PN_seq(1:f_chip));
            j=f_chip*i+1;
        end
        j=1;
        for i=1:m
            s1=0;
            for k=j:j+f_chip-1
                s1=s1+msg_demod(k);
            end
            if s1>=6
                msg_demod_rec(i)=1;
            else
                msg_demod_rec(i)=0;
            end
            j=f_chip*i+1;
        end
        
        diff=inf_bits-msg_demod_rec;
        n_err=n_err+sum(abs(diff));
        n_bits=n_bits+length(inf_bits);
    end
    BER(jj)=n_err/n_bits
end
semilogy(snr_dB,BER,'or-','LineWidth',2);
axis([0 26 10^-4 1]);
grid on;



























































































