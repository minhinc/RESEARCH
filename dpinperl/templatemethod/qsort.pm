##
 * qsort.pm
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
package qsort;
sub new {
my $class=shift;
bless {},$class;
}
sub sort {
my ($ref,@a)=@_;
print "array to be sorted:",map("$_,",@a),"\n";
$ref->sorti(0,$#a,\@a);
print "sorted array:",map("$_,",@a),"\n";
}
sub sorti {
my ($ref,$m,$n,$a)=@_;
if($m<$n) {
$i=$m;$j=$n+1;
do {
do {
$i=$i+1;
}while $i<=$n && $ref->compare1(${$a}[$i],${$a}[$m]);
do {
$j=$j-1;
}while $ref->compare2($$a[$j],$$a[$m]);
if($i<$j) {
$t=$$a[$i];$$a[$i]=$$a[$j];$$a[$j]=$t;
}
}while $i<$j;
$t=$$a[$j];$$a[$j]=$$a[$m];$$a[$m]=$t;
$ref->sorti($m,$j-1,$a);
$ref->sorti($j+1,$n,$a);
}
}
1;
