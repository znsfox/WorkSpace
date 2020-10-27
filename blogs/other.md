vim  /etc/sysconfig/network-scripts/ifcfg-ens33

master     192.168.126.11

slave1     192.168.126.12

slave2     192.168.126.13

zookeeper:         zkServer.sh start-foreground

hbase:    http://192.168.126.11:16010

[root@master conf]# vim hbase-site.xml 
<configuration>
<property> 
    <name>hbase.rootdir</name> 
    <value>hdfs://master:9000/hbase</value> 
  </property> 
  <property> 
    <name>hbase.cluster.distributed</name> 
    <value>true</value> 
  </property> 
  <property> 
    <name>hbase.zookeeper.quorum</name> 
    <value>master,slave1,slave2</value> 
  </property> 
  <property> 
    <name>hbase.zookeeper.property.dataDir</name> 
    <value>/usr/local/zookeeper/zookeeper-3.4.10/data</value> 
  </property> 
  <property>
    <name>hbase.tmp.dir</name>
    <value>/usr/local/hbase/data/tmp</value>
  </property>
  <property> 
    <name>hbase.master</name> 
    <value>hdfs://master:60000</value> 
  </property>
  <property>
    <name>hbase.master.info.port</name>
    <value>16010</value>
  </property>
  <property>
    <name>hbase.regionserver.info.port</name>
    <value>16030</value>
  </property>
</configuration>



core_site.xml master



jansson.x86_64                      java-1.8.0-openjdk-headless.x86_64
jasper-libs.x86_64                  java-1.8.0-openjdk.x86_64
java-1.8.0-openjdk-devel.x86_64     javapackages-filesystem.noarch



rpm -e --nodeps   java-1.8.0-openjdk-headless.x86_64



http://192.168.126.11:9870



niz 68 35g