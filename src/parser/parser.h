#ifndef PARSER_H
# define PARSER_H

enum block_type
{
    ROCK,
    AIR,
    END
};

struct map
{
    int width;
    int height;
    enum block_type **block_type;
};

#endif
