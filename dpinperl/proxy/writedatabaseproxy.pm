##
 * writedatabaseproxy.pm
 # Design Patterns in Perl
 # Copyright (c) 2015-2016 Minh Inc www.minhinc.com
 #
 # This file is part of DesignPatternsInPerl
 #
 # DesignPatternsInPerl
 # modify it under the terms of the GNU Lesser General Public
 # License as published by the Free Software Foundation; either
 # version 2.1 of the License, or (at your option) any later version.
 #
 # DesignPatternsInPerl
 # but WITHOUT ANY WARRANTY; without even the implied warranty of
 # MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 # Lesser General Public License for more details.
 #
 # You should have received a copy of the GNU Lesser General Public
 # License along with Mgmp; if not, write to the Free Software
 # Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301 USA
##
package writedatabaseproxy;
use base qw(database);
sub new {
my $class=shift;
my $ref=$class->SUPER::new;
$ref->{TARGET}=$class->gettargetdatabase();
$ref->{CACHE}=$class->gettablecache();
$ref;
}
sub addtable {
my ($ref, $tableid, $table)=@_;
$ref->{TARGET}->addtable($tableid, $table);
$ref->{CACHE}->addtable($tableid, {SIZE=>scalar @$table,THRESHOLD=>0.8});
}
sub gettable {
my ($ref,$tableid)=@_;
$ref->{TARGET}->gettable($tableid);
}
sub gettablesize {
my ($ref, $tableid)=@_;
$ref->{CACHE}->{$tableid}->{SIZE};
}
1; 
