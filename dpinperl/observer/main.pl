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

use scheduler;
use subject;
use observer;
use sharedmem;

my $sharedmem=new sharedmem;
my $subject=new subject(10,110,$sharedmem);
my $indianbidder=new observer(100,$sharedmem);
my $canadianbidder=new observer(40,$sharedmem);
my $americanbidder=new observer(80,$sharedmem);
my $chinesebidder=new observer(90,$sharedmem);
my $austrailianbidder=new observer(10,$sharedmem);
my $japanesebidder=new observer(120,$sharedmem);
$subject->register($indianbidder,$canadianbidder,$americanbidder,$chinesebidder,$austrailianbidder,$japanesebidder);
new scheduler($subject,$indianbidder,$canadianbidder,$americanbidder,$chinesebidder,$austrailianbidder,$japanesebidder)->start;
