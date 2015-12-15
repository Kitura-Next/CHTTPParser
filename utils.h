//
//  utils.h
//  EnterpriseSwift
//
//  Created by Samuel Kallner on 10/28/15.
//  Copyright © 2015 IBM. All rights reserved.
//

#ifndef utils_h
#define utils_h

const char* get_method(http_parser* parser);
unsigned int get_upgrade_value(http_parser* parser);
unsigned int get_status_code(http_parser* parser);

/* Result structure for http_parser_parse_url().
 *
 * Callers should index into field_data[] with UF_* values iff field_set
 * has the relevant (1 << UF_*) bit set. As a courtesy to clients (and
 * because we probably have padding left over), we convert any port to
 * a uint16_t.
 */
struct http_parser_url_field_data {
    uint16_t off;               /* Offset into buffer in which field starts */
    uint16_t len;               /* Length of run in buffer */
};

struct http_parser_url_url {
    uint16_t field_set;           /* Bitmask of (1 << UF_*) values */
    uint16_t port;                /* Converted UF_PORT string */
    
    struct http_parser_url_field_data field_data[UF_MAX];
};

int http_parser_parse_url_url (const char *buf, size_t buflen,
                          int is_connect,
                               struct http_parser_url_url *u);

#endif /* utils_h */
