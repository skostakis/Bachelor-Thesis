! External file for manipulating the simulation parameters

! Settings used in the main program
Main:numberOfEvents = 100000         ! number of events to generate
Main:timesAllowErrors = 100         ! how many aborts before run stops

! Settings related to output in init(), next() and stat()
Init:showChangedSettings = on      ! list changed settings
Init:showChangedParticleData = on  ! list changed particle data
Next:numberCount = 1000            ! print message every n events
Next:numberShowInfo = 1            ! print event information n times
Next:numberShowProcess = 1         ! print process record n times
Next:numberShowEvent = 0           ! print event record n times

! Possibility to suppress informative output
Print:quiet = on

! Beam parameter settings
Beams:idA = -11                            ! first beam,  e+ = -11, p = 2212, pbar = -2212
Beams:idB =  11                            ! second beam, e- =  11, p = 2212, pbar = -2212
Beams:eCM = 100.                  ! CM energy of collision
Beams:allowVertexSpread = off      ! allow varying x,y,z vertex position: http://home.thep.lu.se/~torbjorn/pythia81html/BeamParameters.html
Beams:offsetVertexX = -0.56        ! mm (ATLAS: https://twiki.cern.ch/twiki/bin/view/AtlasPublic/BeamSpotPublicResults )
Beams:offsetVertexY = -0.56        !
Beams:offsetVertexZ = 0.           !
Beams:sigmaVertexX  = 0.015        ! mm (in ATLAS this is about 15microns = 0.015mm)
Beams:sigmaVertexY  = 0.015        !
Beams:sigmaVertexZ  = 45.          ! mm (in ATLAS this is about 45mm)

! Turn off everything except hard process
PartonLevel:all = on
HadronLevel:all = on

WeakSingleBoson:ffbar2gmZ = on     ! single gamma/Z0 generation
WeakZ0:gmZmode = 0                 ! this is the default anyway full gamma^*/Z^0 structure, with interference included.

! Specific decays: Switch off all Z0 decays and then switch back on those to electrons or muons:
23:onMode = off
23:onIfAny = 13                    ! switch on only muons
! 23:onIfAny = 11 13               ! switch on only electrons and muons
