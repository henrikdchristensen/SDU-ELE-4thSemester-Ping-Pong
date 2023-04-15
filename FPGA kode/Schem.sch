<?xml version="1.0" encoding="UTF-8"?>
<drawing version="7">
    <attr value="spartan3e" name="DeviceFamilyName">
        <trait delete="all:0" />
        <trait editname="all:0" />
        <trait edittrait="all:0" />
    </attr>
    <netlist>
        <signal name="hs_out" />
        <signal name="vs_out" />
        <signal name="red_out(2:0)" />
        <signal name="green_out(2:0)" />
        <signal name="blue_out(1:0)" />
        <signal name="SClk" />
        <signal name="SS" />
        <signal name="MOSI" />
        <signal name="XLXN_11(18:0)" />
        <signal name="XLXN_13" />
        <signal name="XLXN_17(0:0)" />
        <signal name="Data(0:0)" />
        <signal name="LED(18:0)" />
        <signal name="SW(7:0)" />
        <signal name="XLXN_27(0:0)" />
        <signal name="tgl_btn(1:0)" />
        <signal name="clk50_in" />
        <signal name="AN(3:0)" />
        <signal name="abcdefg(7:0)" />
        <port polarity="Output" name="hs_out" />
        <port polarity="Output" name="vs_out" />
        <port polarity="Output" name="red_out(2:0)" />
        <port polarity="Output" name="green_out(2:0)" />
        <port polarity="Output" name="blue_out(1:0)" />
        <port polarity="Input" name="SClk" />
        <port polarity="Input" name="SS" />
        <port polarity="Input" name="MOSI" />
        <port polarity="Output" name="Data(0:0)" />
        <port polarity="Output" name="LED(18:0)" />
        <port polarity="Input" name="SW(7:0)" />
        <port polarity="Input" name="tgl_btn(1:0)" />
        <port polarity="Input" name="clk50_in" />
        <port polarity="Output" name="AN(3:0)" />
        <port polarity="Output" name="abcdefg(7:0)" />
        <blockdef name="SPI">
            <timestamp>2015-4-16T12:48:29</timestamp>
            <rect width="256" x="64" y="-256" height="256" />
            <line x2="0" y1="-224" y2="-224" x1="64" />
            <line x2="0" y1="-160" y2="-160" x1="64" />
            <line x2="0" y1="-96" y2="-96" x1="64" />
            <line x2="0" y1="-32" y2="-32" x1="64" />
            <line x2="384" y1="-224" y2="-224" x1="320" />
            <line x2="384" y1="-128" y2="-128" x1="320" />
            <rect width="64" x="320" y="-44" height="24" />
            <line x2="384" y1="-32" y2="-32" x1="320" />
        </blockdef>
        <blockdef name="Memory">
            <timestamp>2015-4-16T12:47:8</timestamp>
            <rect width="512" x="32" y="32" height="1344" />
            <line x2="32" y1="80" y2="80" style="linewidth:W" x1="0" />
            <line x2="32" y1="112" y2="112" style="linewidth:W" x1="0" />
            <line x2="32" y1="208" y2="208" style="linewidth:W" x1="0" />
            <line x2="32" y1="272" y2="272" x1="0" />
            <line x2="32" y1="432" y2="432" style="linewidth:W" x1="0" />
            <line x2="32" y1="624" y2="624" x1="0" />
            <line x2="544" y1="368" y2="368" style="linewidth:W" x1="576" />
        </blockdef>
        <blockdef name="VGA">
            <timestamp>2015-5-6T8:18:1</timestamp>
            <rect width="64" x="352" y="20" height="24" />
            <line x2="416" y1="32" y2="32" x1="352" />
            <rect width="64" x="352" y="84" height="24" />
            <line x2="416" y1="96" y2="96" x1="352" />
            <line x2="0" y1="-416" y2="-416" x1="64" />
            <line x2="0" y1="-288" y2="-288" x1="64" />
            <rect width="64" x="0" y="-172" height="24" />
            <line x2="0" y1="-160" y2="-160" x1="64" />
            <rect width="64" x="0" y="-44" height="24" />
            <line x2="0" y1="-32" y2="-32" x1="64" />
            <line x2="416" y1="-416" y2="-416" x1="352" />
            <line x2="416" y1="-352" y2="-352" x1="352" />
            <line x2="416" y1="-288" y2="-288" x1="352" />
            <rect width="64" x="352" y="-236" height="24" />
            <line x2="416" y1="-224" y2="-224" x1="352" />
            <rect width="64" x="352" y="-172" height="24" />
            <line x2="416" y1="-160" y2="-160" x1="352" />
            <rect width="64" x="352" y="-108" height="24" />
            <line x2="416" y1="-96" y2="-96" x1="352" />
            <rect width="64" x="352" y="-44" height="24" />
            <line x2="416" y1="-32" y2="-32" x1="352" />
            <rect width="288" x="64" y="-448" height="576" />
        </blockdef>
        <block symbolname="SPI" name="XLXI_2">
            <blockpin signalname="clk50_in" name="Clk" />
            <blockpin signalname="SClk" name="SClk" />
            <blockpin signalname="SS" name="SS" />
            <blockpin signalname="MOSI" name="MOSI" />
            <blockpin signalname="XLXN_17(0:0)" name="WE" />
            <blockpin signalname="Data(0:0)" name="Databus" />
            <blockpin signalname="LED(18:0)" name="Adrbus(18:0)" />
        </block>
        <block symbolname="Memory" name="XLXI_3">
            <blockpin signalname="LED(18:0)" name="addra(18:0)" />
            <blockpin signalname="Data(0:0)" name="dina(0:0)" />
            <blockpin signalname="XLXN_17(0:0)" name="wea(0:0)" />
            <blockpin signalname="clk50_in" name="clka" />
            <blockpin signalname="XLXN_11(18:0)" name="addrb(18:0)" />
            <blockpin signalname="XLXN_13" name="clkb" />
            <blockpin signalname="XLXN_27(0:0)" name="doutb(0:0)" />
        </block>
        <block symbolname="VGA" name="XLXI_4">
            <blockpin signalname="clk50_in" name="clk50_in" />
            <blockpin signalname="XLXN_27(0:0)" name="color" />
            <blockpin signalname="SW(7:0)" name="SW(7:0)" />
            <blockpin signalname="tgl_btn(1:0)" name="tgl_btn(1:0)" />
            <blockpin signalname="hs_out" name="hs_out" />
            <blockpin signalname="vs_out" name="vs_out" />
            <blockpin signalname="XLXN_13" name="clk_synch" />
            <blockpin signalname="red_out(2:0)" name="red_out(2:0)" />
            <blockpin signalname="green_out(2:0)" name="green_out(2:0)" />
            <blockpin signalname="blue_out(1:0)" name="blue_out(1:0)" />
            <blockpin signalname="XLXN_11(18:0)" name="adr(18:0)" />
            <blockpin signalname="AN(3:0)" name="AN(3:0)" />
            <blockpin signalname="abcdefg(7:0)" name="abcdefg(7:0)" />
        </block>
    </netlist>
    <sheet sheetnum="1" width="3520" height="2720">
        <instance x="448" y="1264" name="XLXI_2" orien="R0">
        </instance>
        <branch name="hs_out">
            <wire x2="2032" y1="112" y2="112" x1="1776" />
        </branch>
        <branch name="vs_out">
            <wire x2="2032" y1="176" y2="176" x1="1776" />
        </branch>
        <branch name="red_out(2:0)">
            <wire x2="2032" y1="304" y2="304" x1="1776" />
        </branch>
        <branch name="green_out(2:0)">
            <wire x2="2032" y1="368" y2="368" x1="1776" />
        </branch>
        <branch name="blue_out(1:0)">
            <wire x2="2032" y1="432" y2="432" x1="1776" />
        </branch>
        <branch name="SClk">
            <wire x2="448" y1="1104" y2="1104" x1="416" />
        </branch>
        <iomarker fontsize="28" x="416" y="1104" name="SClk" orien="R180" />
        <branch name="SS">
            <wire x2="448" y1="1168" y2="1168" x1="416" />
        </branch>
        <iomarker fontsize="28" x="416" y="1168" name="SS" orien="R180" />
        <branch name="MOSI">
            <wire x2="448" y1="1232" y2="1232" x1="416" />
        </branch>
        <iomarker fontsize="28" x="416" y="1232" name="MOSI" orien="R180" />
        <iomarker fontsize="28" x="2032" y="432" name="blue_out(1:0)" orien="R0" />
        <iomarker fontsize="28" x="2032" y="368" name="green_out(2:0)" orien="R0" />
        <iomarker fontsize="28" x="2032" y="304" name="red_out(2:0)" orien="R0" />
        <iomarker fontsize="28" x="2032" y="176" name="vs_out" orien="R0" />
        <iomarker fontsize="28" x="2032" y="112" name="hs_out" orien="R0" />
        <branch name="XLXN_11(18:0)">
            <wire x2="1248" y1="688" y2="1152" x1="1248" />
            <wire x2="1312" y1="1152" y2="1152" x1="1248" />
            <wire x2="1872" y1="688" y2="688" x1="1248" />
            <wire x2="1872" y1="496" y2="496" x1="1776" />
            <wire x2="1872" y1="496" y2="688" x1="1872" />
        </branch>
        <iomarker fontsize="28" x="352" y="1040" name="clk50_in" orien="R180" />
        <branch name="XLXN_17(0:0)">
            <wire x2="848" y1="1040" y2="1040" x1="832" />
            <wire x2="1312" y1="928" y2="928" x1="848" />
            <wire x2="848" y1="928" y2="1040" x1="848" />
        </branch>
        <branch name="Data(0:0)">
            <wire x2="1056" y1="1136" y2="1136" x1="832" />
            <wire x2="1056" y1="832" y2="832" x1="976" />
            <wire x2="1056" y1="832" y2="1136" x1="1056" />
            <wire x2="1312" y1="832" y2="832" x1="1056" />
        </branch>
        <branch name="LED(18:0)">
            <wire x2="1072" y1="1232" y2="1232" x1="832" />
            <wire x2="1072" y1="752" y2="800" x1="1072" />
            <wire x2="1072" y1="800" y2="1232" x1="1072" />
            <wire x2="1312" y1="800" y2="800" x1="1072" />
        </branch>
        <instance x="1312" y="720" name="XLXI_3" orien="R0">
        </instance>
        <branch name="XLXN_13">
            <wire x2="1168" y1="64" y2="1344" x1="1168" />
            <wire x2="1312" y1="1344" y2="1344" x1="1168" />
            <wire x2="1792" y1="64" y2="64" x1="1168" />
            <wire x2="1792" y1="64" y2="240" x1="1792" />
            <wire x2="1792" y1="240" y2="240" x1="1776" />
        </branch>
        <iomarker fontsize="28" x="976" y="832" name="Data(0:0)" orien="R180" />
        <iomarker fontsize="28" x="1072" y="752" name="LED(18:0)" orien="R270" />
        <iomarker fontsize="28" x="1056" y="368" name="SW(7:0)" orien="R180" />
        <iomarker fontsize="28" x="1056" y="496" name="tgl_btn(1:0)" orien="R180" />
        <branch name="clk50_in">
            <wire x2="432" y1="1040" y2="1040" x1="352" />
            <wire x2="448" y1="1040" y2="1040" x1="432" />
            <wire x2="432" y1="112" y2="992" x1="432" />
            <wire x2="432" y1="992" y2="1040" x1="432" />
            <wire x2="1312" y1="992" y2="992" x1="432" />
            <wire x2="1360" y1="112" y2="112" x1="432" />
            <wire x2="1360" y1="112" y2="128" x1="1360" />
        </branch>
        <branch name="tgl_btn(1:0)">
            <wire x2="1360" y1="496" y2="496" x1="1056" />
        </branch>
        <branch name="SW(7:0)">
            <wire x2="1360" y1="368" y2="368" x1="1056" />
        </branch>
        <branch name="XLXN_27(0:0)">
            <wire x2="1360" y1="240" y2="240" x1="1296" />
            <wire x2="1296" y1="240" y2="720" x1="1296" />
            <wire x2="1952" y1="720" y2="720" x1="1296" />
            <wire x2="1952" y1="720" y2="1088" x1="1952" />
            <wire x2="1952" y1="1088" y2="1088" x1="1888" />
        </branch>
        <instance x="1360" y="528" name="XLXI_4" orien="R0">
        </instance>
        <branch name="AN(3:0)">
            <wire x2="2032" y1="560" y2="560" x1="1776" />
        </branch>
        <branch name="abcdefg(7:0)">
            <wire x2="2032" y1="624" y2="624" x1="1776" />
        </branch>
        <iomarker fontsize="28" x="2032" y="560" name="AN(3:0)" orien="R0" />
        <iomarker fontsize="28" x="2032" y="624" name="abcdefg(7:0)" orien="R0" />
    </sheet>
</drawing>