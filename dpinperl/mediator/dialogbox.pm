##
 * dialogbox.pm
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
package dialogbox;
sub new {
my $class=shift;
bless {},$class;
}
sub registermenu {
my ($ref,$shape)=@_;
$ref->{MENU}=$shape;
}
sub registerbutton {
my ($ref,$shape)=@_;
$ref->{BUTTON}=$shape;
}
sub registercombobox {
my ($ref,$shape)=@_;
$ref->{COMBOBOX}=$shape;
}
sub informmenu {
my ($ref,$shape)=@_;
print "dialogbox::menu clicked id:",$shape->id,"\n";
}
sub informbutton {
my ($ref,$shape)=@_;
print "dialogbox::button clicked id:",$shape->id,"\n";
}
sub informcombobox {
my ($ref,$shape)=@_;
print "dialogbox::combobox clicked id:",$shape->id,"\n";
}
1;
