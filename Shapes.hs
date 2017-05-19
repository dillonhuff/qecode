module Shapes where

data SymVar = SymVar String deriving (Eq, Ord, Show)

data SymPoint2 = SymPoint2 SymVar SymVar deriving (Eq, Ord, Show)

data SymPoint3 = SymPoint3 SymVar SymVar SymVar deriving (Eq, Ord, Show)

data Shape =
  Square SymPoint2 SymVar |

  Rectangle SymPoint2 SymPoint2 |

  Circle SymPoint2 SymVar |

  Cube SymPoint3 SymVar |

  Cuboid SymPoint3 SymPoint3 |

  Sphere SymPoint3 SymVar |

  Plane SymPoint3 SymVar
  
  deriving (Eq, Ord, Show)
