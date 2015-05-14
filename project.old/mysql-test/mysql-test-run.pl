#!/usr/bin/perl
# Call mtr in out-of-source build
$ENV{MTR_BINDIR} = "/Users/sens/Developer/mysql-5.6.23/project";
chdir("/Users/sens/Developer/mysql-5.6.23/mysql-test");
exit(system($^X, "/Users/sens/Developer/mysql-5.6.23/mysql-test/mysql-test-run.pl", @ARGV) >> 8);
