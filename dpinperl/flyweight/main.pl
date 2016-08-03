##
 * main.pl
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
use strict;
use warnings;
use housefactory;
use locationcontext;

my $housefactoryref=new housefactory;
$housefactoryref->gethouse('A')->build(new locationcontext(10, 1));
$housefactoryref->gethouse('B')->build(new locationcontext(10, 2));
$housefactoryref->gethouse('A')->build(new locationcontext(10, 3));
$housefactoryref->gethouse('A')->build(new locationcontext(10, 4));
$housefactoryref->gethouse('B')->build(new locationcontext(10, 5));
$housefactoryref->gethouse('B')->build(new locationcontext(10, 7));
$housefactoryref->gethouse('C')->build(new locationcontext(11, 1));
$housefactoryref->gethouse('C')->build(new locationcontext(11, 2));
$housefactoryref->gethouse('C')->build(new locationcontext(11, 4));
$housefactoryref->gethouse('D')->build(new locationcontext(11, 5));
$housefactoryref->gethouse('D')->build(new locationcontext(11, 7));
